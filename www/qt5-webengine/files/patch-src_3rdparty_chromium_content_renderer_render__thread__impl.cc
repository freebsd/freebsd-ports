--- src/3rdparty/chromium/content/renderer/render_thread_impl.cc.orig	2021-12-15 16:12:54 UTC
+++ src/3rdparty/chromium/content/renderer/render_thread_impl.cc
@@ -173,7 +173,7 @@
 
 #if defined(OS_MAC)
 #include <malloc/malloc.h>
-#else
+#elif !defined(OS_BSD)
 #include <malloc.h>
 #endif
 
