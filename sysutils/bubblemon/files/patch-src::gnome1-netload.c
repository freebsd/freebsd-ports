--- src/gnome1-netload.c.orig	Thu Dec 26 00:39:30 2002
+++ src/gnome1-netload.c	Thu Dec 26 00:40:09 2002
@@ -22,6 +22,7 @@
  * This is the Gnome 1 specific network load measuring stuff.
  */
 
+#include <sys/types.h>
 #include <stdlib.h>
 #include <stdio.h>
 #include <glibtop/netload.h>
