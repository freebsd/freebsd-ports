--- ./include/includes.h.orig	2009-03-12 09:47:20.000000000 +0000
+++ ./include/includes.h	2009-03-14 05:49:10.000000000 +0000
@@ -870,7 +870,7 @@
 #endif
 
 #ifndef SIGRTMIN
-#define SIGRTMIN 32
+#define SIGRTMIN NSIG
 #endif
 
 #ifndef MAP_FILE
