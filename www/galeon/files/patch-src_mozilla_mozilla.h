--- src/mozilla/mozilla.h.orig	Mon Apr  7 23:44:55 2003
+++ src/mozilla/mozilla.h	Mon Apr  7 23:45:01 2003
@@ -256,14 +256,14 @@
 				  char *force_character_set);
 
 /* Cookies manager */
-void mozilla_set_url_permission (const gchar *imgURL, gint type,
+void mozilla_set_url_permission (const gchar *imgURL, guint type,
 				 gboolean allow);
 GList *mozilla_list_cookies (void);
-void mozilla_set_permission (GaleonEmbed *embed, gboolean permit, 
-				    int type);
-GList *mozilla_get_permissions (int type);
+void mozilla_set_permission (GaleonEmbed *embed, gboolean allow, 
+			     guint type);
+GList *mozilla_get_permissions (guint type);
 gboolean mozilla_remove_cookies (GList *gone, gboolean block);
-gboolean mozilla_remove_permissions (GList *gone, int type);
+gboolean mozilla_remove_permissions (GList *gone, guint type);
 
 /* Password Manager */
 GList *mozilla_list_passwords (PasswordType type);
