--- src/3rdparty/chromium/content/public/common/content_constants.h.orig	2021-12-15 16:12:54 UTC
+++ src/3rdparty/chromium/content/public/common/content_constants.h
@@ -70,7 +70,7 @@ CONTENT_EXPORT std::string GetCorsExemptRequestedWithH
 // it at run time.
 CONTENT_EXPORT std::string GetCorsExemptRequestedWithHeaderName();
 
-#if defined(OS_LINUX) || defined(OS_CHROMEOS)
+#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
 // The OOM score adj constants
 // The highest and lowest assigned OOM score adjustment (oom_score_adj) for
 // renderers and extensions used by the OomPriority Manager.
