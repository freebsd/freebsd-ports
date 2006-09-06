--- src/dynamic-plugins/sf_engine/sf_snort_plugin_api.h.orig	Fri Feb  3 01:49:10 2006
+++ src/dynamic-plugins/sf_engine/sf_snort_plugin_api.h	Wed Sep  6 13:53:28 2006
@@ -36,8 +36,8 @@
 #include "stdio.h"
 
 #ifndef WIN32
-#include <netinet/in.h>
 #include <sys/types.h>
+#include <netinet/in.h>
 #else
 typedef unsigned char u_int8_t;
 typedef unsigned short u_int16_t;
