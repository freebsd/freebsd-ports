--- content/renderer/render_thread_impl.cc.orig	2020-11-13 06:36:43 UTC
+++ content/renderer/render_thread_impl.cc
@@ -173,7 +173,7 @@
 
 #if defined(OS_MAC)
 #include <malloc/malloc.h>
-#else
+#elif !defined(OS_BSD)
 #include <malloc.h>
 #endif
 
