--- common.hh.orig	Mon Jun 12 11:46:27 2006
+++ common.hh	Mon Jun 12 11:47:03 2006
@@ -208,7 +208,7 @@
 //@{
 
 #ifdef _LARGEFILE_SOURCE
-#ifdef _MACOSX
+#if defined (_MACOSX) || defined (__FreeBSD__)
 		#define   _OFF_d   "%qd"
 		#define   _OFF_x   "%qx"
 #else
