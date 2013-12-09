--- ./lives-plugins/plugins/decoders/asf_decoder.c.orig	2013-12-05 19:16:35.348036750 +0100
+++ ./lives-plugins/plugins/decoders/asf_decoder.c	2013-12-05 19:18:43.232061256 +0100
@@ -32,7 +32,7 @@
 #include <stdlib.h>
 #include <ctype.h>
 #ifndef IS_MINGW
-#ifndef IS_SOLARIS
+#ifndef __FreeBSD__
 #include <endian.h>
 #endif
 #endif
