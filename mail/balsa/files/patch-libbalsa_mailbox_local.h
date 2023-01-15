--- libbalsa/mailbox_local.h.orig	Sun May  6 13:57:53 UTC
+++ libbalsa/mailbox_local.h
@@ -79,7 +79,7 @@ struct _LibBalsaMailboxLocalClass {
     gint (*check_files)(const gchar * path, gboolean create);
     void (*set_path)(LibBalsaMailboxLocal * local, const gchar * path);
     void (*remove_files)(LibBalsaMailboxLocal * local);
-    guint (*fileno)(LibBalsaMailboxLocal * local, guint msgno);
+    guint (*sti_fileno)(LibBalsaMailboxLocal * local, guint msgno);
     LibBalsaMailboxLocalMessageInfo *(*get_info)(LibBalsaMailboxLocal * local,
                                                  guint msgno);
 };
