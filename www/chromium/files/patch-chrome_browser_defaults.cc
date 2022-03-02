--- chrome/browser/defaults.cc.orig	2022-02-28 16:54:41 UTC
+++ chrome/browser/defaults.cc
@@ -50,7 +50,7 @@ const bool kSyncAutoStarts = false;
 
 // TODO(crbug.com/1052397): Revisit the macro expression once build flag switch
 // of lacros-chrome is complete.
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS) || BUILDFLAG(IS_BSD)
 const bool kScrollEventChangesTab = true;
 #else
 const bool kScrollEventChangesTab = false;
