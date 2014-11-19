--- eel/eel-editable-label.c.orig	2014-04-03 11:36:31.849369101 +0000
+++ eel/eel-editable-label.c	2014-04-03 11:37:01.819371871 +0000
@@ -36,6 +36,11 @@
 #include <gtk/gtk.h>
 #include <gdk/gdkkeysyms.h>
 
+/* g_memmove is removed in glib 2.40 */
+#if GLIB_CHECK_VERSION (2, 39, 0)
+#define g_memmove memmove
+#endif
+
 enum {
   MOVE_CURSOR,
   POPULATE_POPUP,
