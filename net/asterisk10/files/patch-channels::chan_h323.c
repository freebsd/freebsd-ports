
$FreeBSD$

--- channels/chan_h323.c.orig	Tue Jan 13 11:24:26 2004
+++ channels/chan_h323.c	Fri Jan 30 01:47:34 2004
@@ -54,6 +54,7 @@
 #include <fcntl.h>
 #include <netdb.h>
 #include <sys/signal.h>
+#include <netinet/in_systm.h>
 #include <netinet/ip.h>
 
 
