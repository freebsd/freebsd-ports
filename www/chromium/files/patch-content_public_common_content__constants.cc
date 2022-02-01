--- content/public/common/content_constants.cc.orig	2021-12-31 00:57:32 UTC
+++ content/public/common/content_constants.cc
@@ -48,7 +48,7 @@ std::string GetCorsExemptRequestedWithHeaderName() {
   return base::JoinString(pieces, "-");
 }
 
-#if defined(OS_LINUX) || defined(OS_CHROMEOS)
+#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
 const int kLowestRendererOomScore = 300;
 const int kHighestRendererOomScore = 1000;
 
