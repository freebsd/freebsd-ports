--- applications/aufs/afpos.c.orig	Wed Feb  5 17:48:07 2003
+++ applications/aufs/afpos.c	Wed Feb  5 17:48:45 2003
@@ -4776,7 +4776,7 @@
 #if !(defined(__FreeBSD__) || defined(__NetBSD__))
   extern char *sys_errlist[];
 #endif
-  extern int sys_nerr;
+  extern __const int sys_nerr;
   static char buf[50];
   int serrno;

