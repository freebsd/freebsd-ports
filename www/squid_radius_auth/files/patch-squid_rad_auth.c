--- squid_rad_auth.c.orig	Mon Nov 28 03:03:59 2005
+++ squid_rad_auth.c	Mon Nov 28 03:04:29 2005
@@ -46,6 +46,7 @@
 #include	<sys/types.h>
 #include	<sys/socket.h>
 #include	<netinet/in.h>
+#include <sys/time.h>
 
 #include	<ctype.h>
 #include	<stdio.h>
