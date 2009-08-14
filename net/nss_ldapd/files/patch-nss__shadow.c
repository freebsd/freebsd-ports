--- ./nss/shadow.c.orig	2009-05-29 21:23:03.000000000 +0000
+++ ./nss/shadow.c	2009-08-02 22:32:27.000000000 +0000
@@ -22,6 +22,7 @@
 
 #include "config.h"
 
+#ifdef HAVE_SHADOW_H
 #include <string.h>
 #include <nss.h>
 #include <errno.h>
@@ -73,3 +74,6 @@
 {
   NSS_ENDENT(spentfp);
 }
+
+#endif
+
