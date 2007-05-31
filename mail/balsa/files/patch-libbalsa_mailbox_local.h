--- libbalsa/mailbox_local.h.orig	Sun May  6 13:57:53 2007
+++ libbalsa/mailbox_local.h	Thu May 31 01:04:10 2007
@@ -79,7 +79,7 @@ struct _LibBalsaMailboxLocalClass {
     gint (*check_files)(const gchar * path, gboolean create);
     void (*set_path)(LibBalsaMailboxLocal * local, const gchar * path);
     void (*remove_files)(LibBalsaMailboxLocal * local);
-    guint (*fileno)(LibBalsaMailboxLocal * local, guint msgno);
+    guint (*sti_fileno)(LibBalsaMailboxLocal * local, guint msgno);
     LibBalsaMailboxLocalMessageInfo *(*get_info)(LibBalsaMailboxLocal * local,
                                                  guint msgno);
 };
