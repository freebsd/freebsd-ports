--- imap/outbox.c.orig	Tue Jul 13 00:35:27 2004
+++ imap/outbox.c	Sun Dec 31 13:24:50 2006
@@ -92,10 +92,10 @@
 		argv[5]=NULL;
 	}
 
-	return (sendmsg(message, argv, errlogger));
+	return (ci_sendmsg(message, argv, errlogger));
 }
 
-int sendmsg(const char *message, char **argv, void (*err_func)(char *))
+int ci_sendmsg(const char *message, char **argv, void (*err_func)(char *))
 {
 	char buffer[512];
 	int i;
