--- get_info6_freebsd.c.orig	Fri Oct 12 14:27:48 2001
+++ get_info6_freebsd.c	Thu Sep  4 17:01:19 2003
@@ -10,6 +10,7 @@
  *
  */
 
+#define _WANT_UCRED	1
 #include <unistd.h>              /* for close */
 #include <pwd.h>                 /* for getpwuid */
 
