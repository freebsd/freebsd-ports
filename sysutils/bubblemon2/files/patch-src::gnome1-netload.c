--- src/gnome1-netload.c.orig	Tue Jul  8 02:12:27 2003
+++ src/gnome1-netload.c	Tue Jul  8 02:13:12 2003
@@ -22,6 +22,7 @@
  * This is the Gnome 1 specific network load measuring stuff.
  */
 
+#include <sys/types.h>
 #include <stdlib.h>
 #include <stdio.h>
 #include <glibtop/netload.h>
