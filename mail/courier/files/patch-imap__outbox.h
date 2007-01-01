--- imap/outbox.h.orig	Tue May 27 17:55:10 2003
+++ imap/outbox.h	Sun Dec 31 13:24:27 2006
@@ -10,7 +10,7 @@
 
 int check_outbox(const char *message, const char *mailbox);
 int is_outbox(const char *mailbox);
-int sendmsg(const char *message, char **argv, void (*err_func)(char *));
+int ci_sendmsg(const char *message, char **argv, void (*err_func)(char *));
 const char *defaultSendFrom();
 
 #endif
