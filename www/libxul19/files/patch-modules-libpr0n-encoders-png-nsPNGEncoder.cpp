--- modules/libpr0n/encoders/png/nsPNGEncoder.cpp	2010-03-28 13:48:53.000000000 +0200
+++ modules/libpr0n/encoders/png/nsPNGEncoder.cpp.orig	2010-03-28 13:46:50.000000000 +0200
@@ -135,7 +135,7 @@ NS_IMETHODIMP nsPNGEncoder::StartImageEn
 
   // initialize
   mPNG = png_create_write_struct(PNG_LIBPNG_VER_STRING,
-                                 png_voidp_NULL,
+                                 NULL,
                                  ErrorCallback,
                                  ErrorCallback);
   if (! mPNG)
