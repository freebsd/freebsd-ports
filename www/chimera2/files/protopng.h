/*  Eliminate a couple of errors from image/image.c for missing prototype */
#include "image_format.h"
void pngInit(void (*lineProc)(void *, int, int), void *closure, struct ifs_vector *ifsv);
