--- content/renderer/renderer_webkitplatformsupport_impl.cc.orig	2014-10-10 09:15:31 UTC
+++ content/renderer/renderer_webkitplatformsupport_impl.cc
@@ -92,7 +92,7 @@
 
 #if defined(OS_POSIX)
 #include "base/file_descriptor_posix.h"
-#if !defined(OS_MACOSX) && !defined(OS_ANDROID)
+#if !defined(OS_MACOSX) && !defined(OS_ANDROID) && !defined(OS_BSD)
 #include <map>
 #include <string>
 
@@ -184,7 +184,7 @@
   scoped_refptr<ThreadSafeSender> thread_safe_sender_;
 };
 
-#if defined(OS_ANDROID)
+#if defined(OS_ANDROID) || defined(OS_BSD)
 // WebKit doesn't use WebSandboxSupport on android so we don't need to
 // implement anything here.
 class RendererWebKitPlatformSupportImpl::SandboxSupport {
@@ -277,7 +277,7 @@
 }
 
 blink::WebSandboxSupport* RendererWebKitPlatformSupportImpl::sandboxSupport() {
-#if defined(OS_ANDROID)
+#if defined(OS_ANDROID) || defined(OS_BSD)
   // WebKit doesn't use WebSandboxSupport on android.
   return NULL;
 #else
@@ -573,7 +573,7 @@
   return FontLoader::CGFontRefFromBuffer(font_data, font_data_size, out);
 }
 
-#elif defined(OS_ANDROID)
+#elif defined(OS_ANDROID) || defined(OS_BSD)
 
 // WebKit doesn't use WebSandboxSupport on android so we don't need to
 // implement anything here. This is cleaner to support than excluding the
