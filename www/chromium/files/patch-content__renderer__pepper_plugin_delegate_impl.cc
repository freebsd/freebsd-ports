--- content/renderer/pepper_plugin_delegate_impl.cc.orig	2011-09-19 00:22:00.000000000 +0300
+++ content/renderer/pepper_plugin_delegate_impl.cc	2011-09-19 00:22:35.000000000 +0300
@@ -141,7 +141,7 @@
     return reinterpret_cast<intptr_t>(dib_->handle());
 #elif defined(OS_MACOSX)
     return static_cast<intptr_t>(dib_->handle().fd);
-#elif defined(OS_LINUX)
+#elif defined(OS_LINUX) || defined(OS_FREEBSD)
     return static_cast<intptr_t>(dib_->handle());
 #endif
   }
