--- chrome/browser/shell_integration.h.orig	2026-02-11 09:05:39 UTC
+++ chrome/browser/shell_integration.h
@@ -188,7 +188,7 @@ std::u16string GetAppShortcutsSubdirName();
 #endif
 
 #if BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || \
-    BUILDFLAG(IS_WIN)
+    BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
 // Returns the URL scheme for google-chrome:// URLs.
 // This varies based on channel, branding, and platform to ensure that
 // different installations do not collide. For example:
