--- lib/mbox_maildir.c.orig	Tue Jun 24 14:37:19 2003
+++ lib/mbox_maildir.c	Tue Jun 24 14:38:18 2003
@@ -190,7 +190,7 @@
 				    (MDIR_F_EXPIRE | MDIR_F_REMOVE) &&
 				    cxn->flags & MAILBOX_F_FALSEUIDL ?
 				    time(NULL) : mbox->msg[mbox->count].d_time,
-				    mbox->msg[mbox->count].path,
+				    dp->d_name,
 				    mbox->msg[mbox->count].bytes);
 				MD5Init(&context);
 				MD5Update(&context, (unsigned char *)uidldat,
