--- modules/libpr0n/decoders/png/nsPNGDecoder.cpp.orig	2009-05-02 18:39:49.000000000 +0200
+++ modules/libpr0n/decoders/png/nsPNGDecoder.cpp	2012-05-09 13:14:57.000000000 +0200
@@ -116,7 +116,7 @@ void nsPNGDecoder::CreateFrame(png_uint_
   nsresult rv = mImage->AppendFrame(x_offset, y_offset, width, height, format,
                                     &mImageData, &imageDataLength);
   if (NS_FAILED(rv))
-    longjmp(mPNG->jmpbuf, 5); // NS_ERROR_OUT_OF_MEMORY
+    longjmp(png_jmpbuf(mPNG), 5); // NS_ERROR_OUT_OF_MEMORY
 
   mFrameRect.x = x_offset;
   mFrameRect.y = y_offset;
@@ -376,7 +376,7 @@ static NS_METHOD ReadDataOut(nsIInputStr
   }
 
   // we need to do the setjmp here otherwise bad things will happen
-  if (setjmp(decoder->mPNG->jmpbuf)) {
+  if (setjmp(png_jmpbuf(decoder->mPNG))) {
     png_destroy_read_struct(&decoder->mPNG, &decoder->mInfo, NULL);
 
     decoder->mError = PR_TRUE;
@@ -443,7 +443,8 @@ PNGGetColorProfile(png_structp png_ptr, 
   // First try to see if iCCP chunk is present
   if (png_get_valid(png_ptr, info_ptr, PNG_INFO_iCCP)) {
     png_uint_32 profileLen;
-    char *profileData, *profileName;
+    unsigned char *profileData;
+    char *profileName;
     int compression;
 
     png_get_iCCP(png_ptr, info_ptr, &profileName, &compression,
@@ -551,7 +552,7 @@ info_callback(png_structp png_ptr, png_i
   /* limit image dimensions (bug #251381) */
 #define MOZ_PNG_MAX_DIMENSION 1000000L
   if (width > MOZ_PNG_MAX_DIMENSION || height > MOZ_PNG_MAX_DIMENSION)
-    longjmp(decoder->mPNG->jmpbuf, 1);
+    longjmp(png_jmpbuf(decoder->mPNG), 1);
 #undef MOZ_PNG_MAX_DIMENSION
 
   if (color_type == PNG_COLOR_TYPE_PALETTE)
@@ -667,7 +668,7 @@ info_callback(png_structp png_ptr, png_i
     // the image hasn't been inited yet
     decoder->mImage->Init(width, height, decoder->mObserver);
   } else if (containerWidth != PRInt32(width) || containerHeight != PRInt32(height)) {
-    longjmp(decoder->mPNG->jmpbuf, 5); // NS_ERROR_UNEXPECTED
+    longjmp(png_jmpbuf(decoder->mPNG), 5); // NS_ERROR_UNEXPECTED
   }
 
   if (decoder->mObserver)
@@ -693,14 +694,14 @@ info_callback(png_structp png_ptr, png_i
     decoder->mCMSLine =
       (PRUint8 *)nsMemory::Alloc(bpp[channels] * width);
     if (!decoder->mCMSLine)
-      longjmp(decoder->mPNG->jmpbuf, 5); // NS_ERROR_OUT_OF_MEMORY
+      longjmp(png_jmpbuf(decoder->mPNG), 5); // NS_ERROR_OUT_OF_MEMORY
   }
 
   if (interlace_type == PNG_INTERLACE_ADAM7) {
     if (height < PR_INT32_MAX / (width * channels))
       decoder->interlacebuf = (PRUint8 *)nsMemory::Alloc(channels * width * height);
     if (!decoder->interlacebuf) {
-      longjmp(decoder->mPNG->jmpbuf, 5); // NS_ERROR_OUT_OF_MEMORY
+      longjmp(png_jmpbuf(decoder->mPNG), 5); // NS_ERROR_OUT_OF_MEMORY
     }
   }
   
@@ -920,7 +921,7 @@ void
 error_callback(png_structp png_ptr, png_const_charp error_msg)
 {
   PR_LOG(gPNGLog, PR_LOG_ERROR, ("libpng error: %s\n", error_msg));
-  longjmp(png_ptr->jmpbuf, 1);
+  longjmp(png_jmpbuf(png_ptr), 1);
 }
 
 
