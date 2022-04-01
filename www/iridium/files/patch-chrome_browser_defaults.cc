--- chrome/browser/defaults.cc.orig	2022-04-01 07:48:30 UTC
+++ chrome/browser/defaults.cc
@@ -48,7 +48,7 @@ const bool kSyncAutoStarts = true;
 const bool kSyncAutoStarts = false;
 #endif
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 const bool kScrollEventChangesTab = true;
 #else
 const bool kScrollEventChangesTab = false;
