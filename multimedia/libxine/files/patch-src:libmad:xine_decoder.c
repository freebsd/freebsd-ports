--- src/libmad/xine_decoder.c.orig	Mon Dec 15 07:13:23 2003
+++ src/libmad/xine_decoder.c	Tue Jan  6 23:43:14 2004
@@ -24,6 +24,7 @@
 
 #include <stdlib.h>
 #include <string.h>
+#include <mad.h>
 
 #define LOG_MODULE "mad_decoder"
 #define LOG_VERBOSE
