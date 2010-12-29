--- ./xbmc/FileSystem/DllLibCurl.cpp.orig	2010-08-25 00:38:59.000000000 +0200
+++ ./xbmc/FileSystem/DllLibCurl.cpp	2010-12-01 12:17:34.236800761 +0100
@@ -84,6 +84,12 @@
 
 void DllLibCurlGlobal::CheckIdle()
 {
+
+#if defined(__FreeBSD__)
+  /* easy_cleanup crash on freebsd with extern python */
+  return;
+#endif
+
   /* avoid locking section here, to avoid stalling gfx thread on loads*/
   if(g_curlReferences == 0)
     return;
