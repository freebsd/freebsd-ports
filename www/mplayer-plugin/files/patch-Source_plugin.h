--- Source/plugin.h.orig	Mon Mar  1 13:29:02 2004
+++ Source/plugin.h	Thu Mar  4 01:29:25 2004
@@ -37,11 +37,9 @@
 
 #ifndef __PLUGIN_H__
 #define __PLUGIN_H__
+#include <cmath>
 #define _XOPEN_SOURCE 500
 
-#ifndef _GNU_SOURCE
-#define _GNU_SOURCE
-#endif
 #ifdef GECKOSDK_ENABLED
 #include "mozilla-config.h"
 #endif
