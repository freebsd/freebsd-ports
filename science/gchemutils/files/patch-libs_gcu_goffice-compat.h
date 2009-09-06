--- libs/gcu/goffice-compat.h.orig	2009-09-06 12:06:55.000000000 +0200
+++ libs/gcu/goffice-compat.h	2009-09-06 12:07:48.000000000 +0200
@@ -48,6 +48,19 @@
 #	define DOUBLE_RGBA_B GO_DOUBLE_RGBA_B
 #	define DOUBLE_RGBA_A GO_DOUBLE_RGBA_A
 #endif
+#ifdef GO_COLOR_FROM_RGBA
+#       define RGBA_TO_UINT GO_COLOR_FROM_RGBA
+#       define RGBA_BLACK GO_COLOR_BLACK
+#       define RGBA_RED GO_COLOR_RED
+#       define UINT_RGBA_R GO_COLOR_UINT_R
+#       define UINT_RGBA_G GO_COLOR_UINT_G
+#       define UINT_RGBA_B GO_COLOR_UINT_B
+#       define UINT_RGBA_A GO_COLOR_UINT_A
+#       define DOUBLE_RGBA_R GO_COLOR_DOUBLE_R
+#       define DOUBLE_RGBA_G GO_COLOR_DOUBLE_G
+#       define DOUBLE_RGBA_B GO_COLOR_DOUBLE_B
+#       define DOUBLE_RGBA_A GO_COLOR_DOUBLE_A
+#endif
 
 #ifdef GO_PLUGIN_SERVICE_CLASS
 #	define GPS_CLASS GO_PLUGIN_SERVICE_CLASS
