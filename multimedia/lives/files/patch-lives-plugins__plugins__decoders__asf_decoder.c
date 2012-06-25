--- ./lives-plugins/plugins/decoders/asf_decoder.c.orig	2012-06-25 19:53:28.000000000 +0200
+++ ./lives-plugins/plugins/decoders/asf_decoder.c	2012-06-25 19:57:21.000000000 +0200
@@ -30,11 +30,6 @@
 #include <fcntl.h>
 #include <unistd.h>
 #include <stdlib.h>
-#ifndef IS_MINGW
-#ifndef IS_SOLARIS
-#include <endian.h>
-#endif
-#endif
 #include <sys/stat.h>
 
 const char *plugin_version="LiVES asf/wmv decoder version 1.0";
