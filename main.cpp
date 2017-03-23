
#include<SDL.h>
#include<SDL_image.h>
#include<iostream>

SDL_Window* window;
SDL_Renderer* renderer;
SDL_Event Event;
SDL_Texture *fondo,*im1,*im2,*im3,*im4,*im5;
SDL_Rect rect_fondo,rect_im1,rect_im2,rect_im3,rect_im4,rect_im5;



int main( int argc, char* args[] )
{
    //Init SDL
      if(SDL_Init(SDL_INIT_EVERYTHING) < 0)
    {
        return 10;
    }
    //Creates a SDL Window
    if((window = SDL_CreateWindow("Image Loading", 100, 100, 500/*WIDTH*/, 250/*HEIGHT*/, SDL_WINDOW_RESIZABLE | SDL_RENDERER_PRESENTVSYNC)) == NULL)
    {
        return 20;
    }
    //SDL Renderer
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED );
    if (renderer == NULL)
    {
        std::cout << SDL_GetError() << std::endl;
        return 30;
    }

    //Init textures
    int w=0,h=0;
    fondo = IMG_LoadTexture(renderer,"fondo.jpg");
    SDL_QueryTexture(fondo, NULL, NULL, &w, &h);
    rect_fondo.x = 0; rect_fondo.y = 0; rect_fondo.w = 1200; rect_fondo.h = 700;

    im1 = IMG_LoadTexture(renderer, "conejo1.png");
    SDL_QueryTexture(im1, NULL, NULL, &w, &h);
    rect_im1.x = 500; rect_im1.y = 500; rect_im1.w = 150; rect_im1.h = 150;

    im2 = IMG_LoadTexture(renderer, "conejo2.png");
    SDL_QueryTexture(im2, NULL, NULL, &w, &h);
    rect_im2.x = 300; rect_im2.y = 300; rect_im2.w = 150; rect_im2.h = 170;

    im3 = IMG_LoadTexture(renderer, "carrot.png");
    SDL_QueryTexture(im3, NULL, NULL, &w, &h);
    rect_im3.x = 600; rect_im3.y = 150; rect_im3.w = 150; rect_im3.h = 170;

    im4 = IMG_LoadTexture(renderer, "hongo.png");
    SDL_QueryTexture(im4, NULL, NULL, &w, &h);
    rect_im4.x = 800; rect_im4.y = 250; rect_im4.w = 150; rect_im4.h = 170;

    im5 = IMG_LoadTexture(renderer, "piedra.png");
    SDL_QueryTexture(im5, NULL, NULL, &w, &h);
    rect_im5.x = 50; rect_im5.y = 100; rect_im5.w = 500; rect_im5.h = 120;

    //Main Loop
    while(true)
    {
        /*while(SDL_PollEvent(&Event))
        {
            if(Event.type == SDL_QUIT)
            {
                return 0;
            }
            if(Event.type == SDL_KEYDOWN)
            {
                if(Event.key.keysym.sym == SDLK_d)
                    rect_im1.x++;
            }
        }*/

        SDL_RenderCopy(renderer, fondo, NULL, &rect_fondo);
        SDL_RenderCopy(renderer, im1, NULL, &rect_im1);
        SDL_RenderCopy(renderer, im2, NULL, &rect_im2);
        SDL_RenderCopy(renderer, im3, NULL, &rect_im3);
        SDL_RenderCopy(renderer, im4, NULL, &rect_im4);
        SDL_RenderCopy(renderer, im5, NULL, &rect_im5);
        SDL_RenderPresent(renderer);
    }

	return 0;
}
