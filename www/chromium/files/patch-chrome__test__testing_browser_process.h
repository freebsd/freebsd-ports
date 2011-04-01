--- ./chrome/test/testing_browser_process.h.orig	2010-12-16 02:12:11.000000000 +0100
+++ ./chrome/test/testing_browser_process.h	2010-12-20 20:15:08.000000000 +0100
@@ -52,7 +52,7 @@
     return NULL;
   }
 
-#if defined(OS_LINUX)
+#if defined(USE_X11)
   virtual base::Thread* background_x11_thread() {
     return NULL;
   }
