--- MailboxP.h	Mon Jul  1 11:13:47 1996
+++ /home/andy/tmp/wrk/MailboxP.h	Sun May 24 00:39:39 1998
@@ -40,12 +40,10 @@
 
 #ifdef SYSV
 #define MAILBOX_DIRECTORY "/usr/mail"
-#else
-#ifdef SVR4
+#elif defined(SVR4) || defined(__FreeBSD__)
 #define MAILBOX_DIRECTORY "/var/mail"
 #else
 #define MAILBOX_DIRECTORY "/usr/spool/mail"
-#endif
 #endif
 
 typedef struct {				/* new fields for mailbox widget */
