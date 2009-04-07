--- ./include/includes.h.orig	2009-04-01 11:48:54.000000000 +0000
+++ ./include/includes.h	2009-04-07 01:39:14.000000000 +0000
@@ -873,7 +873,7 @@
 #endif
 
 #ifndef SIGRTMIN
-#define SIGRTMIN 32
+#define SIGRTMIN NSIG
 #endif
 
 #ifndef MAP_FILE
