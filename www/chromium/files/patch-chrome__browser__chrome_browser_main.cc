--- ./chrome/browser/chrome_browser_main.cc.orig	2014-04-24 22:35:13.000000000 +0200
+++ ./chrome/browser/chrome_browser_main.cc	2014-04-24 23:23:42.000000000 +0200
@@ -973,7 +973,7 @@
   }
 #endif
 
-#if defined(OS_LINUX) || defined(OS_OPENBSD) || defined(OS_MACOSX)
+#if defined(OS_LINUX) || defined(OS_BSD) || defined(OS_MACOSX)
   // Set the product channel for crash reports.
   base::debug::SetCrashKeyValue(crash_keys::kChannel,
       chrome::VersionInfo::GetVersionStringModifier());
