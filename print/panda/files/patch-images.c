--- images.c.orig	2016-06-20 16:04:03 UTC
+++ images.c
@@ -835,7 +835,7 @@ panda_insertPNG (panda_pdf * output, pan
 		 panda_object * imageObj, char *filename)
 {
   FILE *image;
-  unsigned long width, height;
+  png_uint_32 width, height;
   int bitdepth, colourtype, outColourType;
   png_uint_32 i, rowbytes;
   png_structp png;
@@ -854,7 +854,7 @@ panda_insertPNG (panda_pdf * output, pan
 
   // Check that it really is a PNG file
   fread (sig, 1, 8, image);
-  if (!png_check_sig (sig, 8))
+  if (png_sig_cmp (sig, 0, 8))
     panda_error (panda_true, "PNG file was invalid");
 
   // Start decompressing
@@ -1399,7 +1399,7 @@ void
 panda_imagesizePNG (int *width, int *height, char *filename) 
 {
   FILE * image;
-  unsigned long pwidth, pheight;
+  png_uint_32 pwidth, pheight;
   int bitdepth, colourtype;
   png_structp png;
   png_infop info;
@@ -1411,7 +1411,7 @@ panda_imagesizePNG (int *width, int *hei
   
     // Check that it really is a PNG file
     fread (sig, 1, 8, image);
-  if (!png_check_sig (sig, 8))
+  if (png_sig_cmp (sig, 0, 8))
     panda_error (panda_true, "PNG file was invalid");
   
     // Start decompressing
