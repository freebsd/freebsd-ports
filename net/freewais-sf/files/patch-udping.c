--- lib/ir/udping.c.orig	Sun Feb 29 01:27:48 2004
+++ lib/ir/udping.c	Sun Feb 29 01:28:00 2004
@@ -36,7 +36,6 @@
 
 extern uid_t getuid();
 extern int socket();
-extern int sendto();
 extern int close();
 
 static int iamhere(progname)
