--- src/mozilla/mozilla.h.orig	Mon Apr 21 12:32:00 2003
+++ src/mozilla/mozilla.h	Mon Apr 21 12:32:55 2003
@@ -261,7 +261,11 @@
 GList *mozilla_list_cookies (void);
 void mozilla_set_permission (GaleonEmbed *embed, gboolean allow, 
 			     guint type);
+#if MOZILLA_SNAPSHOT > 6
 GList *mozilla_get_permissions (guint type);
+#else
+GList *mozilla_get_permissions (gint type);
+#endif
 gboolean mozilla_remove_cookies (GList *gone, gboolean block);
 gboolean mozilla_remove_permissions (GList *gone, guint type);
 
