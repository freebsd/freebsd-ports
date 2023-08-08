--- libbalsa/mailbox_maildir.c.orig	2023-01-06 18:47:11 UTC
+++ libbalsa/mailbox_maildir.c
@@ -23,6 +23,8 @@
 #endif                          /* HAVE_CONFIG_H */
 
 
+#include <sys/types.h>
+#include <sys/stat.h>
 #include <unistd.h>
 #include <fcntl.h>
 #include <errno.h>
@@ -52,7 +54,7 @@
     /* The message's order when parsing; needed for saving the message
      * tree in a form that will match the msgnos when the mailbox is
      * reopened. */
-    guint fileno;
+    guint mi_fileno;
 };
 #define REAL_FLAGS(flags) ((flags) & LIBBALSA_MESSAGE_FLAGS_REAL)
 #define FLAGS_REALLY_DIFFER(orig_flags, flags) \
@@ -152,7 +154,7 @@
     libbalsa_mailbox_local_class->check_files  = lbm_maildir_check_files;
     libbalsa_mailbox_local_class->set_path     = lbm_maildir_set_path;
     libbalsa_mailbox_local_class->remove_files = lbm_maildir_remove_files;
-    libbalsa_mailbox_local_class->fileno       = lbm_maildir_fileno;
+    libbalsa_mailbox_local_class->sti_fileno       = lbm_maildir_fileno;
     libbalsa_mailbox_local_class->get_info     = lbm_maildir_get_info;
     libbalsa_mailbox_local_class->add_message  = lbm_maildir_add_message;
 }
@@ -369,7 +371,7 @@
 static void
 lbm_maildir_parse(LibBalsaMailboxMaildir *mdir,
                   const gchar            *subdir,
-                  guint                  *fileno)
+                  guint                  *md_fileno)
 {
     const gchar *local_path;
     gchar *path;
@@ -420,12 +422,12 @@
 	    msg_info->key=key;
 	    msg_info->filename=g_strdup(filename);
 	    msg_info->local_info.flags = msg_info->orig_flags = flags;
-	    msg_info->fileno = 0;
+	    msg_info->mi_fileno = 0;
 	}
 	msg_info->subdir = subdir;
-        if (!msg_info->fileno)
+        if (!msg_info->mi_fileno)
             /* First time we saw this key. */
-	    msg_info->fileno = ++*fileno;
+	    msg_info->mi_fileno = ++*md_fileno;
     }
     g_dir_close(dir);
 }
@@ -433,21 +435,21 @@
 static void
 lbm_maildir_parse_subdirs(LibBalsaMailboxMaildir * mdir)
 {
-    guint msgno, fileno = 0;
+    guint msgno, md_fileno = 0;
 
     for (msgno = mdir->msgno_2_msg_info->len; msgno > 0; --msgno) {
         struct message_info *msg_info =
             message_info_from_msgno(mdir, msgno);
-        msg_info->fileno = 0;
+        msg_info->mi_fileno = 0;
     }
 
-    lbm_maildir_parse(mdir, "cur", &fileno);
+    lbm_maildir_parse(mdir, "cur", &md_fileno);
     /* We parse "new" after "cur", so that any recent messages will have
      * higher msgnos than any current messages. That ensures that the
      * message tree saved by LibBalsaMailboxLocal is still valid, and
      * that the new messages will be inserted correctly into the tree by
      * libbalsa_mailbox_local_add_messages. */
-    lbm_maildir_parse(mdir, "new", &fileno);
+    lbm_maildir_parse(mdir, "new", &md_fileno);
 }
 
 static gboolean
@@ -849,7 +851,7 @@
     msg_info =
         message_info_from_msgno((LibBalsaMailboxMaildir *) local, msgno);
 
-    return msg_info->fileno;
+    return msg_info->mi_fileno;
 }
 
 static LibBalsaMailboxLocalMessageInfo *
