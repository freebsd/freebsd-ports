--- net.c.orig	Wed Mar 31 22:16:29 2004
+++ net.c	Tue May 18 21:51:03 2004
@@ -15,6 +15,7 @@
 #include <netinet/in.h>
 #include <arpa/inet.h>
 #include <signal.h>
+#include <limits.h>
 
 #ifndef __OpenBSD__
 #ifndef __FreeBSD__
