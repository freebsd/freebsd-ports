--- pagespeed/kernel/image/image_converter.cc.orig	2017-09-13 22:51:16 UTC
+++ pagespeed/kernel/image/image_converter.cc
@@ -23,6 +23,7 @@ using net_instaweb::MessageHandler;
 
 #include <setjmp.h>
 #include <cstddef>
+#include <zlib.h>
 
 extern "C" {
 #ifdef USE_SYSTEM_LIBPNG
