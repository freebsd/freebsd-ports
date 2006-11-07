--- dns.c.orig	Mon Oct  9 16:11:26 2006
+++ dns.c	Mon Oct  9 16:11:46 2006
@@ -48,11 +48,13 @@
 #include "dns.h"
 #include "net.h"
 
+/*
 #ifdef NO_STRERROR
 extern int sys_nerr;
 extern char *sys_errlist[];
 #define strerror(errno) (((errno) >= 0 && (errno) < sys_nerr) ? sys_errlist[errno] : "unlisted error")
 #endif
+*/
 
 /*  Hmm, it seems Irix requires this  */
 extern int errno;
