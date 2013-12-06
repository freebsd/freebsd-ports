--- ./lives-plugins/plugins/decoders/mpegts_decoder.c.orig	2013-12-05 19:19:20.795023448 +0100
+++ ./lives-plugins/plugins/decoders/mpegts_decoder.c	2013-12-05 19:19:44.882059440 +0100
@@ -30,7 +30,7 @@
 #include <ctype.h>
 #include <sys/stat.h>
 
-#ifndef IS_MINGW
+#ifndef __FreeBSD__
 #include <endian.h>
 #endif
 
