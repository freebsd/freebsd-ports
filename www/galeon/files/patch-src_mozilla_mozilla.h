--- src/mozilla/mozilla.h.orig	Fri Oct 25 20:43:51 2002
+++ src/mozilla/mozilla.h	Thu Apr 10 13:02:14 2003
@@ -256,14 +256,18 @@
 				  char *force_character_set);
 
 /* Cookies manager */
-void mozilla_set_url_permission (const gchar *imgURL, gint type,
+void mozilla_set_url_permission (const gchar *imgURL, guint type,
 				 gboolean allow);
 GList *mozilla_list_cookies (void);
-void mozilla_set_permission (GaleonEmbed *embed, gboolean permit, 
-				    int type);
+void mozilla_set_permission (GaleonEmbed *embed, gboolean allow, 
+			     guint type);
+#if MOZILLA_SNAPSHOT > 6
+GList *mozilla_get_permissions (guint type);
+#else
 GList *mozilla_get_permissions (int type);
+#endif
 gboolean mozilla_remove_cookies (GList *gone, gboolean block);
-gboolean mozilla_remove_permissions (GList *gone, int type);
+gboolean mozilla_remove_permissions (GList *gone, guint type);
 
 /* Password Manager */
 GList *mozilla_list_passwords (PasswordType type);
