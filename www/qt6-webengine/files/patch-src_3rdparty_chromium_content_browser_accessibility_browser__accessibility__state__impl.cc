--- src/3rdparty/chromium/content/browser/accessibility/browser_accessibility_state_impl.cc.orig	2026-02-26 14:39:03 UTC
+++ src/3rdparty/chromium/content/browser/accessibility/browser_accessibility_state_impl.cc
@@ -296,7 +296,7 @@ BrowserAccessibilityStateImpl* BrowserAccessibilitySta
 
 // On Android, Mac, Windows and Linux there are platform-specific subclasses.
 #if (!BUILDFLAG(IS_ANDROID) && !BUILDFLAG(IS_WIN) && !BUILDFLAG(IS_MAC) && \
-    !BUILDFLAG(IS_LINUX) && !BUILDFLAG(IS_CHROMEOS)) || BUILDFLAG(IS_QTWEBENGINE)
+    !BUILDFLAG(IS_LINUX) && !BUILDFLAG(IS_CHROMEOS) && !BUILDFLAG(IS_BSD)) || BUILDFLAG(IS_QTWEBENGINE)
 // static
 std::unique_ptr<BrowserAccessibilityStateImpl>
 BrowserAccessibilityStateImpl::Create() {
