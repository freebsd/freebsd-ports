--- chrome/browser/chrome_browser_main.cc.orig	2014-10-02 17:39:45 UTC
+++ chrome/browser/chrome_browser_main.cc
@@ -947,7 +947,7 @@
   }
 #endif
 
-#if defined(OS_LINUX) || defined(OS_OPENBSD) || defined(OS_MACOSX)
+#if defined(OS_LINUX) || defined(OS_BSD) || defined(OS_MACOSX)
   // Set the product channel for crash reports.
   base::debug::SetCrashKeyValue(crash_keys::kChannel,
       chrome::VersionInfo::GetVersionStringModifier());
