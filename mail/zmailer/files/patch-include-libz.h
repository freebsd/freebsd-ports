--- include/libz.h.orig	Tue Aug 14 13:23:53 2007
+++ include/libz.h	Tue Aug 14 13:29:34 2007
@@ -53,6 +53,7 @@
 
 /* dottedquad.c */
 #ifdef HAVE_NETINET_IN_H
+# include <sys/socket.h>
 # include <netinet/in.h>
 #endif
 #ifdef IN_CLASSA
