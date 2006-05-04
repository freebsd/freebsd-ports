--- dns.c.orig	Thu Mar 23 02:45:58 2006
+++ dns.c	Wed May  3 18:48:01 2006
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
@@ -1357,7 +1359,7 @@
 #ifdef ENABLE_IPV6
 /* Returns an ip6.arpa character string. */
 void addr2ip6arpa( ip_t * ip, char * buf ) {
-  char * p = (char *) ip;
+  unsigned char * p = (unsigned char *) ip;
   char * b = buf;
   int i;
 
