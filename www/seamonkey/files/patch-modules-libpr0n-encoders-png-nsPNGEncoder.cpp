--- modules/libpr0n/encoders/png/nsPNGEncoder.cpp	2010-03-28 13:48:53.000000000 +0200
+++ modules/libpr0n/encoders/png/nsPNGEncoder.cpp.orig	2010-03-28 13:46:50.000000000 +0200
@@ -111,9 +111,9 @@
 
   // initialize
   png_struct* png_ptr = png_create_write_struct(PNG_LIBPNG_VER_STRING,
-                                                png_voidp_NULL,
-                                                png_error_ptr_NULL,
-                                                png_error_ptr_NULL);
+                                                NULL,
+                                                NULL,
+                                                NULL);
   if (! png_ptr)
     return NS_ERROR_OUT_OF_MEMORY;
   png_info* info_ptr = png_create_info_struct(png_ptr);
