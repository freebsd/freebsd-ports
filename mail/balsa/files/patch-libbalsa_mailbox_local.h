--- libbalsa/mailbox_local.h.orig	Thu Dec 29 01:49:05 2005
+++ libbalsa/mailbox_local.h	Thu Dec 29 01:49:13 2005
@@ -66,7 +66,7 @@ struct _LibBalsaMailboxLocalClass {
     gint (*check_files)(const gchar * path, gboolean create);
     void (*set_path)(LibBalsaMailboxLocal * local, const gchar * path);
     void (*remove_files)(LibBalsaMailboxLocal * local);
-    guint (*fileno)(LibBalsaMailboxLocal * local, guint msgno);
+    guint (*sti_fileno)(LibBalsaMailboxLocal * local, guint msgno);
 };
 
 GObject *libbalsa_mailbox_local_new(const gchar * path, gboolean create);
