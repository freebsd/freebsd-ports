--- ./include/includes.h.orig	2009-06-23 09:35:13.000000000 +0000
+++ ./include/includes.h	2009-06-26 00:41:37.000000000 +0000
@@ -873,7 +873,7 @@
 #endif
 
 #ifndef SIGRTMIN
-#define SIGRTMIN 32
+#define SIGRTMIN NSIG
 #endif
 
 #ifndef MAP_FILE
