--- mbox/mbox.c.orig	2025-01-13 09:21:08 UTC
+++ mbox/mbox.c
@@ -895,7 +895,7 @@ static bool mbox_mbox_open_append(struct Mailbox *m, O
     }
     FREE(&tmp_path);
 
-    adata->fp = mutt_file_fopen(mailbox_path(m), (flags & MUTT_NEWFOLDER) ? "w+" : "a+");
+    adata->fp = mutt_file_fopen(mailbox_path(m), "a+");
     if (!adata->fp)
     {
       mutt_perror("%s", mailbox_path(m));
