--- content/renderer/renderer_webkitplatformsupport_impl.cc.orig	2013-04-30 10:20:40.000000000 +0300
+++ content/renderer/renderer_webkitplatformsupport_impl.cc	2013-05-07 21:11:09.000000000 +0300
@@ -67,7 +67,7 @@
 #include "third_party/WebKit/Source/Platform/chromium/public/mac/WebSandboxSupport.h"
 #endif
 
-#if defined(OS_POSIX) && !defined(OS_MACOSX) && !defined(OS_ANDROID)
+#if defined(OS_POSIX) && !defined(OS_MACOSX) && !defined(OS_ANDROID) && !defined(OS_BSD)
 #include <map>
 #include <string>
 
@@ -146,7 +146,7 @@
   DISALLOW_COPY_AND_ASSIGN(Hyphenator);
 };
 
-#if defined(OS_ANDROID)
+#if defined(OS_ANDROID) || defined(OS_BSD)
 // WebKit doesn't use WebSandboxSupport on android so we don't need to
 // implement anything here.
 class RendererWebKitPlatformSupportImpl::SandboxSupport {
@@ -237,7 +237,7 @@
 }
 
 WebKit::WebSandboxSupport* RendererWebKitPlatformSupportImpl::sandboxSupport() {
-#if defined(OS_ANDROID)
+#if defined(OS_ANDROID) || defined(OS_BSD)
   // WebKit doesn't use WebSandboxSupport on android.
   return NULL;
 #else
@@ -534,7 +534,7 @@
   return FontLoader::CGFontRefFromBuffer(font_data, font_data_size, out);
 }
 
-#elif defined(OS_ANDROID)
+#elif defined(OS_ANDROID) || defined(OS_BSD)
 
 // WebKit doesn't use WebSandboxSupport on android so we don't need to
 // implement anything here. This is cleaner to support than excluding the
