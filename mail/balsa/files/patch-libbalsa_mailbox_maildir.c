--- libbalsa/mailbox_maildir.c.orig	Tue Dec 27 04:44:40 2005
+++ libbalsa/mailbox_maildir.c	Thu Dec 29 01:52:57 2005
@@ -25,6 +25,8 @@
 #define _XOPEN_SOURCE          500
 #define _XOPEN_SOURCE_EXTENDED 1
 
+#include <sys/types.h>
+#include <sys/stat.h>
 #include <unistd.h>
 #include <fcntl.h>
 #include <errno.h>
@@ -50,7 +52,7 @@ struct message_info {
     /* The message's order when parsing; needed for saving the message
      * tree in a form that will match the msgnos when the mailbox is
      * reopened. */
-    guint fileno;
+    guint mi_fileno;
 };
 #define REAL_FLAGS(flags) (flags & LIBBALSA_MESSAGE_FLAGS_REAL)
 #define FLAGS_REALLY_DIFFER(orig_flags, flags) \
@@ -194,7 +196,7 @@ libbalsa_mailbox_maildir_class_init(LibB
     libbalsa_mailbox_local_class->set_path     = lbm_maildir_set_path;
     libbalsa_mailbox_local_class->remove_files = lbm_maildir_remove_files;
     libbalsa_mailbox_local_class->load_message = lbm_maildir_load_message;
-    libbalsa_mailbox_local_class->fileno       = lbm_maildir_fileno;
+    libbalsa_mailbox_local_class->sti_fileno       = lbm_maildir_fileno;
 }
 
 static void
@@ -408,7 +410,7 @@ static LibBalsaMessageFlag parse_filenam
 }
 
 static void lbm_maildir_parse(LibBalsaMailboxMaildir * mdir,
-                              const gchar *subdir, guint * fileno)
+                              const gchar *subdir, guint * md_fileno)
 {
     gchar *path;
     GDir *dir;
@@ -463,12 +465,12 @@ static void lbm_maildir_parse(LibBalsaMa
 	    msg_info->key=key;
 	    msg_info->filename=g_strdup(filename);
 	    msg_info->flags = msg_info->orig_flags = flags;
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
@@ -476,16 +478,16 @@ static void lbm_maildir_parse(LibBalsaMa
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
-    lbm_maildir_parse(mdir, "new", &fileno);
+    lbm_maildir_parse(mdir, "cur", &md_fileno);
+    lbm_maildir_parse(mdir, "new", &md_fileno);
 }
 
 static gboolean
@@ -927,7 +929,7 @@ lbm_maildir_fileno(LibBalsaMailboxLocal 
     msg_info =
         message_info_from_msgno((LibBalsaMailboxMaildir *) local, msgno);
 
-    return msg_info->fileno;
+    return msg_info->mi_fileno;
 }
 
 /* Called with mailbox locked. */
