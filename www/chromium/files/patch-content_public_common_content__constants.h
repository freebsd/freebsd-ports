--- content/public/common/content_constants.h.orig	2020-05-15 15:08:45 UTC
+++ content/public/common/content_constants.h
@@ -65,7 +65,7 @@ CONTENT_EXPORT extern const int kDefaultDetachableCanc
 CONTENT_EXPORT extern const char kCorsExemptPurposeHeaderName[];
 CONTENT_EXPORT extern const char kCorsExemptRequestedWithHeaderName[];
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
 // The OOM score adj constants
 // The highest and lowest assigned OOM score adjustment (oom_score_adj) for
 // renderers and extensions used by the OomPriority Manager.
