--- modules/libpr0n/decoders/png/nsPNGDecoder.cpp.orig	2009-05-02 18:39:49.000000000 +0200
+++ modules/libpr0n/decoders/png/nsPNGDecoder.cpp	2012-05-09 13:14:57.000000000 +0200
@@ -171,7 +171,7 @@
   }
 
   // we need to do the setjmp here otherwise bad things will happen
-  if (setjmp(decoder->mPNG->jmpbuf)) {
+  if (setjmp(png_jmpbuf(decoder->mPNG))) {
     png_destroy_read_struct(&decoder->mPNG, &decoder->mInfo, NULL);
 
     decoder->mError = PR_TRUE;
@@ -227,7 +227,7 @@
   if (width > MOZ_PNG_MAX_DIMENSION || height > MOZ_PNG_MAX_DIMENSION) {
     nsPNGDecoder *decoder = NS_STATIC_CAST(nsPNGDecoder*,
                                            png_get_progressive_ptr(png_ptr));
-    longjmp(decoder->mPNG->jmpbuf, 1);
+    longjmp(png_jmpbuf(decoder->mPNG), 1);
   }
 #undef MOZ_PNG_MAX_DIMENSION
 
@@ -307,7 +307,7 @@
 
   decoder->mImage = do_CreateInstance("@mozilla.org/image/container;1");
   if (!decoder->mImage)
-    longjmp(decoder->mPNG->jmpbuf, 5); // NS_ERROR_OUT_OF_MEMORY
+    longjmp(png_jmpbuf(decoder->mPNG), 5); // NS_ERROR_OUT_OF_MEMORY
 
   decoder->mImageLoad->SetImage(decoder->mImage);
 
@@ -319,7 +319,7 @@
 
   decoder->mFrame = do_CreateInstance("@mozilla.org/gfx/image/frame;2");
   if (!decoder->mFrame)
-    longjmp(decoder->mPNG->jmpbuf, 5); // NS_ERROR_OUT_OF_MEMORY
+    longjmp(png_jmpbuf(decoder->mPNG), 5); // NS_ERROR_OUT_OF_MEMORY
 
   gfx_format format;
 
@@ -341,7 +341,7 @@
   // then initalize the frame and append it to the container
   nsresult rv = decoder->mFrame->Init(0, 0, width, height, format, 24);
   if (NS_FAILED(rv))
-    longjmp(decoder->mPNG->jmpbuf, 5); // NS_ERROR_OUT_OF_MEMORY
+    longjmp(png_jmpbuf(decoder->mPNG), 5); // NS_ERROR_OUT_OF_MEMORY
 
   decoder->mImage->AppendFrame(decoder->mFrame);
 
@@ -362,7 +362,7 @@
       decoder->ibpr = bpr;
     decoder->interlacebuf = (PRUint8 *)nsMemory::Alloc(decoder->ibpr*height);
     if (!decoder->interlacebuf) {
-      longjmp(decoder->mPNG->jmpbuf, 5); // NS_ERROR_OUT_OF_MEMORY
+      longjmp(png_jmpbuf(decoder->mPNG), 5); // NS_ERROR_OUT_OF_MEMORY
     }            
   }
 
@@ -555,7 +555,7 @@
 error_callback(png_structp png_ptr, png_const_charp error_msg)
 {
   PR_LOG(gPNGLog, PR_LOG_ERROR, ("libpng error: %s\n", error_msg));
-  longjmp(png_ptr->jmpbuf, 1);
+  longjmp(png_jmpbuf(png_ptr), 1);
 }
 
 
