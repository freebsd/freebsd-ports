--- eel/eel-editable-label.c.orig	2014-04-06 22:20:58.028840920 +0000
+++ eel/eel-editable-label.c	2014-04-06 22:21:50.378838503 +0000
@@ -44,6 +44,12 @@
 #define GtkEditableInterface GtkEditableClass
 #endif
 
+/* g_memmove got removed in glib 2.40 */
+#if GLIB_CHECK_VERSION (2, 39, 0)
+#define g_memmove memmove
+#endif
+
+
 enum
 {
     MOVE_CURSOR,
