--- decode.c.orig	Wed Dec  4 22:40:42 2002
+++ decode.c	Sat Dec 14 07:25:35 2002
@@ -8,7 +8,6 @@
 #include "mm_accel.h"
 #include "attributes.h"
 #include "mmx.h"
-#include "malloc.h"
 
 extern FILE* log;
 
@@ -21,7 +20,7 @@
 Mpeg2dec::Mpeg2dec(uint32_t mm_accel)
       {
       config.flags = mm_accel;
-      picture      = (picture_t*)memalign (16, sizeof (picture_t));
+      picture      = (picture_t*)malloc(sizeof (picture_t));
       memset(picture, 0, sizeof (picture_t));
       frames       = 0;
       frame_ptr[0] = 0;
@@ -63,7 +62,7 @@
       int size  = width() * height() / 4;
       if (frames)
             free(frames);
-      frames = (unsigned char*)memalign(64, size*18);
+      frames = (unsigned char*)malloc(size*18);
       unsigned char* alloc = frames;
 
       for (int i = 0; i < 3; i++) {
