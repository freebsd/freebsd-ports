--- ./chrome/browser/chrome_browser_main.cc.orig	2014-08-12 21:01:47.000000000 +0200
+++ ./chrome/browser/chrome_browser_main.cc	2014-08-13 09:56:56.000000000 +0200
@@ -926,7 +926,7 @@
   }
 #endif
 
-#if defined(OS_LINUX) || defined(OS_OPENBSD) || defined(OS_MACOSX)
+#if defined(OS_LINUX) || defined(OS_BSD) || defined(OS_MACOSX)
   // Set the product channel for crash reports.
   base::debug::SetCrashKeyValue(crash_keys::kChannel,
       chrome::VersionInfo::GetVersionStringModifier());
