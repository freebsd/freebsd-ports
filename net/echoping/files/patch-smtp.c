--- smtp.c.orig	2019-12-29 10:14:41 UTC
+++ smtp.c
@@ -8,7 +8,7 @@
 
 #ifdef SMTP
 
-char            big_recvline[MAXTOREAD];
+static char	big_recvline[MAXTOREAD];
 
 int
 smtp_read_response_from_server(FILE * fs)
