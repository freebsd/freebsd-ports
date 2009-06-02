--- ./src/systemplugin.h.orig	2008-07-15 19:14:28.000000000 +0400
+++ ./src/systemplugin.h	2009-06-01 22:02:34.000000000 +0400
@@ -18,6 +18,7 @@
 #ifndef _SYSTEM_PLUGIN_H_
 #define _SYSTEM_PLUGIN_H_
 
+#include <time.h>
 #include "fileplugin.h"
 
 class SystemPlugin : public FilePlugin {
