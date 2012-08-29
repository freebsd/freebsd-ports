--- ./mod_auth_imap.c.orig	2006-05-08 01:22:43.000000000 +0200
+++ ./mod_auth_imap.c	2012-08-25 19:06:59.000000000 +0200
@@ -170,7 +170,7 @@
     tcp_gets(Sock,result,500);
 
     //skip lines that start with "*"
-    if (strncmp(result,"* ",2 == 0)) {
+    if (strncmp(result,"* ",2) == 0) {
 	tcp_gets(Sock,result,500);
     }
 
@@ -188,6 +188,11 @@
     tcp_puts(Sock,buf);
     tcp_gets(Sock,result,500);
 
+    //skip lines that start with "*"
+    if (strncmp(result,"* ",2) == 0) {
+       tcp_gets(Sock,result,500);
+    }
+
     if (strncmp(result,"A002 OK",7) == 0) {
         if (logflag) {
             ap_log_rerror(APLOG_MARK,APLOG_WARNING|APLOG_NOERRNO,0,r,"mod_auth_imap: Verified login for user %s.", username);
