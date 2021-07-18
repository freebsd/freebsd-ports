--- chrome/browser/defaults.cc.orig	2021-04-14 18:40:53 UTC
+++ chrome/browser/defaults.cc
@@ -46,7 +46,7 @@ const bool kSyncAutoStarts = false;
 
 // TODO(crbug.com/1052397): Revisit the macro expression once build flag switch
 // of lacros-chrome is complete.
-#if defined(OS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS)
+#if defined(OS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS) || defined(OS_BSD)
 const bool kScrollEventChangesTab = true;
 #else
 const bool kScrollEventChangesTab = false;
