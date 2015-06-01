--- src/widget-helper.h.orig	2015-05-27 17:58:56 UTC
+++ src/widget-helper.h
@@ -12,6 +12,10 @@
 #define M_PI 3.1415926536
 #endif
 
+#ifndef ulong
+#define ulong unsigned long
+#endif
+
 #define LIVES_HAS_GRID_WIDGET 0
 #define LIVES_HAS_IMAGE_MENU_ITEM 0
 #define LIVES_HAS_DEVICE_MANAGER 0
