--- get_info4_freebsd.c.orig	Sun Oct 14 07:57:15 2001
+++ get_info4_freebsd.c	Thu Sep  4 17:00:32 2003
@@ -7,6 +7,7 @@
  *
  */
 
+#define _WANT_UCRED	1
 #include <sys/param.h>
 #include <sys/sysctl.h>
 #include <sys/socket.h>
