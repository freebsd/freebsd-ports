--- chrome/browser/privacy_sandbox/incognito/privacy_sandbox_whats_new_survey_service.h.orig	2025-11-01 06:40:37 UTC
+++ chrome/browser/privacy_sandbox/incognito/privacy_sandbox_whats_new_survey_service.h
@@ -16,7 +16,7 @@
 #include "components/keyed_service/core/keyed_service.h"
 #include "content/public/browser/web_contents.h"
 
-#if !BUILDFLAG(IS_WIN) && !BUILDFLAG(IS_MAC) && !BUILDFLAG(IS_LINUX)
+#if !BUILDFLAG(IS_WIN) && !BUILDFLAG(IS_MAC) && !BUILDFLAG(IS_LINUX) && !BUILDFLAG(IS_BSD)
 #error This file should only be included on Win, Mac or Linux
 #endif
 
