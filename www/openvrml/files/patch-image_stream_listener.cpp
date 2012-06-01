--- src/node/vrml97/image_stream_listener.cpp.orig	2010-05-28 17:18:15.927540000 +0200
+++ src/node/vrml97/image_stream_listener.cpp	2012-05-06 15:48:10.000000000 +0200
@@ -39,6 +39,7 @@
 }
 
 # ifdef OPENVRML_ENABLE_PNG_TEXTURES
+# include "pngpriv.h"
 void openvrml_png_info_callback(png_structp png_ptr, png_infop info_ptr)
 {
     using boost::shared_mutex;
