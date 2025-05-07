--- chrome/browser/devtools/features.h.orig	2025-05-07 06:48:23 UTC
+++ chrome/browser/devtools/features.h
@@ -89,7 +89,7 @@ BASE_DECLARE_FEATURE(kDevToolsCssValueTracing);
 
 BASE_DECLARE_FEATURE(kDevToolsAiGeneratedTimelineLabels);
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 BASE_DECLARE_FEATURE(kDevToolsDebuggingRestrictions);
 #endif  // BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
 
