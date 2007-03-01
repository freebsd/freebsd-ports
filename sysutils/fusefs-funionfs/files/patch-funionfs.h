--- funionfs.h.orig	Mon Feb 26 21:06:15 2007
+++ funionfs.h	Mon Feb 26 21:06:40 2007
@@ -2,6 +2,8 @@
 #ifndef _FUNIONFS_H
 #define _FUNIONFS_H
 
+#include <pthread.h>
+
 // use the new API
 
 #define VERSION "0.4.2"
