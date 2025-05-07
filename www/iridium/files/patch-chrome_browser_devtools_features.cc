--- chrome/browser/devtools/features.cc.orig	2025-05-07 06:48:23 UTC
+++ chrome/browser/devtools/features.cc
@@ -157,7 +157,7 @@ BASE_FEATURE(kDevToolsAiGeneratedTimelineLabels,
              "DevToolsAiGeneratedTimelineLabels",
              base::FEATURE_DISABLED_BY_DEFAULT);
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 // If enabled, DevTools does not accept remote debugging connections unless
 // using a non-default user data dir via the --user-data-dir switch.
 BASE_FEATURE(kDevToolsDebuggingRestrictions,
