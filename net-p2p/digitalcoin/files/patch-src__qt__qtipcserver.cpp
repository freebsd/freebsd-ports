--- src/qt/qtipcserver.cpp.orig	2014-01-18 05:21:31.335425774 +0000
+++ src/qt/qtipcserver.cpp	2014-01-18 05:22:33.976421840 +0000
@@ -21,7 +21,7 @@
 
 static void ipcThread2(void* pArg);
 
-#ifdef MAC_OSX
+#if defined(MAC_OSX) || defined(__FreeBSD__)
 // URI handling not implemented on OSX yet
 
 void ipcInit() { }
