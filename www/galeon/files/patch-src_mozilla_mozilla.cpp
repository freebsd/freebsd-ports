--- src/mozilla/mozilla.cpp.orig	Mon Apr 21 12:28:35 2003
+++ src/mozilla/mozilla.cpp	Mon Apr 21 12:31:09 2003
@@ -1102,7 +1102,11 @@
  */
 
 extern "C" GList *
+#if MOZILLA_SNAPSHOT > 6
 mozilla_get_permissions (guint type)
+#else
+mozilla_get_permissions (gint type)
+#endif
 {
 	GList *permissions = NULL;
 	nsresult result;
