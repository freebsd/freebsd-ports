--- chrome/renderer/render_widget.cc.orig	2011-03-23 00:47:39.891641114 +0200
+++ chrome/renderer/render_widget.cc	2011-03-23 00:48:36.043641158 +0200
@@ -888,7 +888,7 @@
       // Close our unused handle.
 #if defined(OS_WIN)
       ::CloseHandle(dib_handle);
-#elif defined(OS_MACOSX)
+#elif defined(OS_MACOSX) || defined(OS_FREEBSD)
       base::SharedMemory::CloseHandle(dib_handle);
 #endif
     }
