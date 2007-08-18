--- ./utils/config.h.orig	2007-08-17 16:06:48.000000000 +0400
+++ ./utils/config.h	2007-08-17 16:06:57.000000000 +0400
@@ -18,6 +18,7 @@
 
 #ifndef _NETSURF_UTILS_CONFIG_H_
 #define _NETSURF_UTILS_CONFIG_H_
+#include <sys/types.h>
 
 /* Try to detect which features the target OS supports */
 
