--- src/PNGwrite.cc.orig	2002-12-19 19:56:35.000000000 +0100
+++ src/PNGwrite.cc	2012-05-05 09:40:41.000000000 +0200
@@ -38,7 +38,7 @@
 	  png_destroy_write_struct(&png_ptr,  (png_infopp)NULL);
 	  return;
   }
-  setjmp(png_ptr->jmpbuf);
+  setjmp( png_jmpbuf(png_ptr));
   png_init_io(png_ptr, fp);
 }
 
