--- content/renderer/renderer_webkitclient_impl.cc.orig	2011-03-20 22:02:04.310852495 +0200
+++ content/renderer/renderer_webkitclient_impl.cc	2011-03-20 22:02:04.460737466 +0200
@@ -55,7 +55,7 @@
 #include "third_party/WebKit/Source/WebKit/chromium/public/mac/WebSandboxSupport.h"
 #endif
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_FREEBSD)
 #include <string>
 #include <map>
 
@@ -113,7 +113,7 @@
   virtual bool ensureFontLoaded(HFONT);
 #elif defined(OS_MACOSX)
   virtual bool loadFont(NSFont* srcFont, ATSFontContainerRef* out);
-#elif defined(OS_LINUX)
+#elif defined(OS_LINUX) || defined(OS_FREEBSD)
   virtual WebKit::WebString getFontFamilyForCharacters(
       const WebKit::WebUChar* characters, size_t numCharacters);
   virtual void getRenderStyleForStrike(
@@ -419,7 +419,7 @@
   return RenderThread::current()->Send(new ViewHostMsg_PreCacheFont(logfont));
 }
 
-#elif defined(OS_LINUX)
+#elif defined(OS_LINUX) || defined(OS_FREEBSD)
 
 WebString RendererWebKitClientImpl::SandboxSupport::getFontFamilyForCharacters(
     const WebKit::WebUChar* characters, size_t num_characters) {
