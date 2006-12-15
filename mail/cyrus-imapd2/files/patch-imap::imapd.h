Index: imap/imapd.h
diff -u imap/imapd.h.orig imap/imapd.h
--- imap/imapd.h.orig	Fri Feb 14 05:15:25 2003
+++ imap/imapd.h	Fri Dec 15 11:35:44 2006
@@ -54,17 +54,8 @@
 /* Authorization state for logged in userid */
 extern struct auth_state *imapd_authstate;
 
-/* True if user is an admin */
-extern int imapd_userisadmin;
-
-/* Currently open mailbox */
-extern struct mailbox *imapd_mailbox;
-
 /* Number of messages in currently open mailbox */
 extern int imapd_exists;
-
-/* Name of client host */
-extern char imapd_clienthost[];
 
 /* List of strings, for fetch and search argument blocks */
 struct strlist {
