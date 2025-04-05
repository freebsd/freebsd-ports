--- content/browser/accessibility/browser_accessibility_state_impl.cc.orig	2025-04-04 08:52:13 UTC
+++ content/browser/accessibility/browser_accessibility_state_impl.cc
@@ -192,7 +192,7 @@ BrowserAccessibilityStateImpl* BrowserAccessibilitySta
 
 // On Android, Mac, Windows and Linux there are platform-specific subclasses.
 #if !BUILDFLAG(IS_ANDROID) && !BUILDFLAG(IS_WIN) && !BUILDFLAG(IS_MAC) && \
-    !BUILDFLAG(IS_LINUX) && !BUILDFLAG(IS_CHROMEOS)
+    !BUILDFLAG(IS_LINUX) && !BUILDFLAG(IS_CHROMEOS) && !BUILDFLAG(IS_BSD)
 // static
 std::unique_ptr<BrowserAccessibilityStateImpl>
 BrowserAccessibilityStateImpl::Create() {
