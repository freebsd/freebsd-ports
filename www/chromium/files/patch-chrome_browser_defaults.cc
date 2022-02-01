--- chrome/browser/defaults.cc.orig	2021-12-14 11:44:58 UTC
+++ chrome/browser/defaults.cc
@@ -50,7 +50,7 @@ const bool kSyncAutoStarts = false;
 
 // TODO(crbug.com/1052397): Revisit the macro expression once build flag switch
 // of lacros-chrome is complete.
-#if defined(OS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS)
+#if defined(OS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS) || defined(OS_BSD)
 const bool kScrollEventChangesTab = true;
 #else
 const bool kScrollEventChangesTab = false;
