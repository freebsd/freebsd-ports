--- gnome-netinfo/util-mii.c.orig	Sat Dec  6 23:30:50 2003
+++ gnome-netinfo/util-mii.c	Sat Dec  6 23:38:14 2003
@@ -39,6 +39,7 @@
  * http://www.national.com/pf/DP/DP83840.html
  */
 
+#ifdef __linux__
 #include <glib.h>
 
 #include <errno.h>
@@ -237,3 +238,4 @@
 	close (sock);
 	return data;
 }
+#endif
