--- src/subgen-image.c.orig	2007-01-12 19:40:42.000000000 -0600
+++ src/subgen-image.c	2010-07-15 19:56:30.000000000 -0600
@@ -203,7 +203,7 @@
     png_struct *ps;
     png_info *pi;
     png_byte **rowp;
-    unsigned long width,height;
+    png_uint_32 width,height;
     int bit_depth,color_type,channels,x,y;
 
     fp=fopen(s->fname,"rb");
