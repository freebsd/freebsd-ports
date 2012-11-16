--- content/renderer/renderer_webkitplatformsupport_impl.cc.orig	2012-11-15 23:43:31.000000000 +0200
+++ content/renderer/renderer_webkitplatformsupport_impl.cc	2012-11-15 23:43:50.000000000 +0200
@@ -62,7 +62,7 @@
 #include "third_party/WebKit/Source/WebKit/chromium/public/platform/mac/WebSandboxSupport.h"
 #endif
 
-#if defined(OS_POSIX) && !defined(OS_MACOSX) && !defined(OS_ANDROID)
+#if defined(OS_POSIX) && !defined(OS_MACOSX) && !defined(OS_ANDROID) && !defined(OS_BSD)
 #include <string>
 #include <map>
 
@@ -117,7 +117,7 @@
                                       int mode);
 };
 
-#if defined(OS_ANDROID)
+#if defined(OS_ANDROID) || defined(OS_BSD)
 // WebKit doesn't use WebSandboxSupport on android so we don't need to
 // implement anything here.
 class RendererWebKitPlatformSupportImpl::SandboxSupport {
@@ -216,7 +216,7 @@
 }
 
 WebKit::WebSandboxSupport* RendererWebKitPlatformSupportImpl::sandboxSupport() {
-#if defined(OS_ANDROID)
+#if defined(OS_ANDROID) || defined(OS_BSD)
   // WebKit doesn't use WebSandboxSupport on android.
   return NULL;
 #else
@@ -463,7 +463,7 @@
   return FontLoader::CGFontRefFromBuffer(font_data, font_data_size, out);
 }
 
-#elif defined(OS_ANDROID)
+#elif defined(OS_ANDROID) || defined(OS_BSD)
 
 // WebKit doesn't use WebSandboxSupport on android so we don't need to
 // implement anything here. This is cleaner to support than excluding the
