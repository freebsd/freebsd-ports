--- extconf.rb.orig	Sun Feb 18 10:29:04 2001
+++ extconf.rb	Wed Mar 28 18:55:31 2001
@@ -1,7 +1,7 @@
 
 require "mkmf"
 
-$LDFLAGS += " -L/usr/local/lib"
+dir_config('panda')
 
 have_library("m", "floor")
 
@@ -9,6 +9,6 @@
     have_library("jpeg", "jpeg_CreateDecompress") &&
     have_library("tiff", "TIFFOpen") &&
     have_library("png", "png_init_io") &&
-	have_library("panda", "pdfopen")
+	have_library("panda", "panda_open")
   create_makefile("panda")
 end
