--- ./include/includes.h.orig	2010-01-14 10:12:10.000000000 +0000
+++ ./include/includes.h	2010-02-05 00:27:01.000000000 +0000
@@ -865,7 +865,7 @@
 #endif
 
 #ifndef SIGRTMIN
-#define SIGRTMIN 32
+#define SIGRTMIN NSIG
 #endif
 
 #ifndef MAP_FILE
