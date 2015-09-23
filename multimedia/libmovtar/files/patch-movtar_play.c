--- movtar_play.c.orig	2001-07-13 21:38:03 UTC
+++ movtar_play.c
@@ -12,7 +12,7 @@
 #include <SDL/SDL.h>
 #include <SDL/SDL_timer.h>
 
-#ifndef IRIX
+#if !defined(IRIX) && !defined(__FreeBSD__)
 #define JPEG_INTERNALS
 #include <jinclude.h>
 #endif
@@ -135,15 +135,15 @@ jpeg_mem_src_reset (j_decompress_ptr cin
 
 /* end of data source manager */
 
-#ifndef IRIX 
+#if !defined(IRIX) && !defined(__FreeBSD__)
 /* Colorspace conversion */
 /* RGB, 32 bits, 8bits each: (Junk), R, G, B */ 
 #if defined(__GNUC__)
 #define int64 unsigned long long
 #endif
-static const int64 te0 = 0x0080008000800080; // -128 << 2
-static const int64 te1 = 0xe9fa7168e9fa7168; // for cb 
-static const int64 te2 = 0x59bad24d59bad24d; // for cr
+static const int64 te0 = 0x0080008000800080ULL; // -128 << 2
+static const int64 te1 = 0xe9fa7168e9fa7168ULL; // for cb 
+static const int64 te2 = 0x59bad24d59bad24dULL; // for cr
 
 METHODDEF(void)
 ycc_rgb32_convert_mmx (j_decompress_ptr cinfo,
@@ -263,9 +263,9 @@ ycc_rgb32_convert_mmx (j_decompress_ptr 
   asm ("emms");
 }
 
-static int64 rb16mask = 0x00f800f800f800f8; // just red and blue remain
-static int64 rb16mult = 0x2000000820000008; // mult/Add factor (see intel appnote 553)
-static int64 g16mask = 0x0000f8000000f800; // just green remains
+static int64 rb16mask = 0x00f800f800f800f8ULL; // just red and blue remain
+static int64 rb16mult = 0x2000000820000008ULL; // mult/Add factor (see intel appnote 553)
+static int64 g16mask = 0x0000f8000000f800ULL; // just green remains
 static int64 rgb16offset = 6; // shift right after the whole stuff
 static const int64 shiftmask = 0xffff; // shift right after the whole stuff
 
@@ -556,7 +556,7 @@ void inline readpicfrommem(void *inbuffe
   jpeg_mem_src_reset(&cinfo, size);
   jpeg_read_header(&cinfo, TRUE);
 
-#ifndef IRIX
+#if !defined(IRIX) && !defined(__FreeBSD__)
   cinfo.dct_method = JDCT_IFAST;
   cinfo.out_color_space = JCS_RGB;
 #else
@@ -568,20 +568,20 @@ void inline readpicfrommem(void *inbuffe
   switch (screen->format->BytesPerPixel)
     {
     case 4:
-#ifndef IRIX
+#if !defined(IRIX) && !defined(__FreeBSD__)
       //printf("Choosing MMX color convert\n");
       cconvert = cinfo.cconvert;
       //cconvert->color_convert = ycc_rgb32_convert_mmx;
 #else
-      fprintf(stderr, "32 bits per pixel can't be decoded by libjpeg on IRIX !\n");
+      fprintf(stderr, "32 bits per pixel can't be decoded by libjpeg on IRIX or FreeBSD !\n");
 #endif
       break;
     case 2:
-#ifndef IRIX
+#if !defined(IRIX) && !defined(__FreeBSD__)
       cconvert = cinfo.cconvert;
       cconvert->color_convert = ycc_rgb16_convert_mmx;
 #else
-      fprintf(stderr, "15/16 bits per pixel can't be decoded by libjpeg on IRIX!");
+      fprintf(stderr, "15/16 bits per pixel can't be decoded by libjpeg on IRIX or FreeBSD !");
 #endif
       break;
     default: break;
@@ -795,7 +795,7 @@ int main(int argc,char** argv)
 
   dump_pixel_format(screen->format);
 
-#ifdef IRIX
+#if defined(IRIX) || defined(__FreeBSD__)
   fprintf(stderr, "Screen parameters haven't been determined yet !\n");
 #else
   calc_rgb16_params(screen->format);
