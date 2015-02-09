--- ./content/renderer/renderer_webkitplatformsupport_impl.cc.orig	2014-04-30 22:41:48.000000000 +0200
+++ ./content/renderer/renderer_webkitplatformsupport_impl.cc	2014-05-04 14:38:48.000000000 +0200
@@ -90,7 +90,7 @@
 
 #if defined(OS_POSIX)
 #include "base/file_descriptor_posix.h"
-#if !defined(OS_MACOSX) && !defined(OS_ANDROID)
+#if !defined(OS_MACOSX) && !defined(OS_ANDROID) && !defined(OS_BSD)
 #include <map>
 #include <string>
 
@@ -178,7 +178,7 @@
   scoped_refptr<ThreadSafeSender> thread_safe_sender_;
 };
 
-#if defined(OS_ANDROID)
+#if defined(OS_ANDROID) || defined(OS_BSD)
 // WebKit doesn't use WebSandboxSupport on android so we don't need to
 // implement anything here.
 class RendererWebKitPlatformSupportImpl::SandboxSupport {
@@ -271,7 +271,7 @@
 }
 
 blink::WebSandboxSupport* RendererWebKitPlatformSupportImpl::sandboxSupport() {
-#if defined(OS_ANDROID)
+#if defined(OS_ANDROID) || defined(OS_BSD)
   // WebKit doesn't use WebSandboxSupport on android.
   return NULL;
 #else
@@ -588,7 +588,7 @@
   return FontLoader::CGFontRefFromBuffer(font_data, font_data_size, out);
 }
 
-#elif defined(OS_ANDROID)
+#elif defined(OS_ANDROID) || defined(OS_BSD)
 
 // WebKit doesn't use WebSandboxSupport on android so we don't need to
 // implement anything here. This is cleaner to support than excluding the
