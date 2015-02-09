--- ./chrome/browser/chrome_browser_main.cc.orig	2014-04-30 22:42:18.000000000 +0200
+++ ./chrome/browser/chrome_browser_main.cc	2014-05-04 14:38:46.000000000 +0200
@@ -972,7 +972,7 @@
   }
 #endif
 
-#if defined(OS_LINUX) || defined(OS_OPENBSD) || defined(OS_MACOSX)
+#if defined(OS_LINUX) || defined(OS_BSD) || defined(OS_MACOSX)
   // Set the product channel for crash reports.
   base::debug::SetCrashKeyValue(crash_keys::kChannel,
       chrome::VersionInfo::GetVersionStringModifier());
