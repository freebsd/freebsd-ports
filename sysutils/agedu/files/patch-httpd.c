--- httpd.c.orig	2020-07-05 01:20:14 UTC
+++ httpd.c
@@ -570,7 +570,7 @@ static int make_listening_sockets(struct listenfds *fd
         portstr = NULL;                /* normalise NULL and empty string */
 
     if (!address) {
-        char hostname[HOST_NAME_MAX];
+        char hostname[_POSIX_HOST_NAME_MAX];
         if (gethostname(hostname, sizeof(hostname)) < 0) {
             perror("hostname");
             return -1;
