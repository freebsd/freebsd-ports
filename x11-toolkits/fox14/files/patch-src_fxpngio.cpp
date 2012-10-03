--- src/fxpngio.cpp.orig	2005-11-19 21:22:25.000000000 +0100
+++ src/fxpngio.cpp	2012-05-07 07:11:22.000000000 +0200
@@ -21,13 +21,13 @@
 *********************************************************************************
 * $Id: fxpngio.cpp,v 1.35.2.1 2005/11/19 20:22:25 fox Exp $                         *
 ********************************************************************************/
+#ifdef HAVE_PNG_H
+#include "png.h"
+#endif
 #include "fxver.h"
 #include "fxdefs.h"
 #include "FXHash.h"
 #include "FXStream.h"
-#ifdef HAVE_PNG_H
-#include "png.h"
-#endif
 
 /*
   Notes:
@@ -76,7 +76,7 @@
   FXStream* store=(FXStream*)png_get_error_ptr(png_ptr);
   store->setError(FXStreamFormat);                      // Flag this as a format error in FXStream
   FXTRACE((100,"Error in png: %s\n",message));
-  longjmp(png_ptr->jmpbuf,1);                           // Bail out
+  longjmp(png_jmpbuf(png_ptr),1);                           // Bail out
   }
 
 
@@ -121,7 +121,7 @@
     }
 
   // Set error handling
-  if(setjmp(png_ptr->jmpbuf)){
+  if(setjmp(png_jmpbuf(png_ptr))){
 
     // Free all of the memory associated with the png_ptr and info_ptr
     png_destroy_read_struct(&png_ptr,&info_ptr,(png_infopp)NULL);
@@ -234,7 +234,7 @@
     }
 
   // Set error handling.
-  if(setjmp(png_ptr->jmpbuf)){
+  if(setjmp(png_jmpbuf(png_ptr))){
     png_destroy_write_struct(&png_ptr,&info_ptr);
     return FALSE;
     }
