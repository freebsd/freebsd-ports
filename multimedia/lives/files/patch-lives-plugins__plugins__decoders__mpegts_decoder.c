--- ./lives-plugins/plugins/decoders/mpegts_decoder.c.orig	2012-06-25 19:55:35.000000000 +0200
+++ ./lives-plugins/plugins/decoders/mpegts_decoder.c	2012-06-25 19:57:03.000000000 +0200
@@ -29,9 +29,6 @@
 #include <stdlib.h>
 #include <sys/stat.h>
 
-#ifndef IS_MINGW
-#include <endian.h>
-#endif
 
 const char *plugin_version="LiVES mpegts decoder version 1.0";
 
