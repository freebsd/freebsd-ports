--- decode.c.orig	Fri Oct 25 16:01:13 2002
+++ decode.c	Fri Oct 25 16:01:31 2002
@@ -21,7 +21,7 @@
 Mpeg2dec::Mpeg2dec(uint32_t mm_accel)
       {
       config.flags = mm_accel;
-      picture      = (picture_t*)memalign (16, sizeof (picture_t));
+      picture      = (picture_t*)malloc(sizeof (picture_t));
       memset(picture, 0, sizeof (picture_t));
       frames       = 0;
       frame_ptr[0] = 0;
@@ -66,7 +66,7 @@
       int size  = width() * height() / 4;
       if (frames)
             free(frames);
-      frames = (unsigned char*)memalign(64, size*18);
+      frames = (unsigned char*)malloc(size*18);
       unsigned char* alloc = frames;
 
       for (int i = 0; i < 3; i++) {
