--- Source/plugin.h.orig	Sat Feb 14 08:00:01 2004
+++ Source/plugin.h	Sat Feb 14 14:53:55 2004
@@ -37,11 +37,8 @@
 
 #ifndef __PLUGIN_H__
 #define __PLUGIN_H__
+#include <cmath>
 #define _XOPEN_SOURCE 500
-
-#ifndef _GNU_SOURCE
-#define _GNU_SOURCE
-#endif
 
 #include "pluginbase.h"
 #include "nsScriptablePeer.h"
