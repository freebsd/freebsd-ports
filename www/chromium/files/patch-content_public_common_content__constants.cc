--- content/public/common/content_constants.cc.orig	2021-04-14 18:41:03 UTC
+++ content/public/common/content_constants.cc
@@ -50,7 +50,7 @@ std::string GetCorsExemptRequestedWithHeaderName() {
   return base::JoinString(pieces, "-");
 }
 
-#if defined(OS_LINUX) || defined(OS_CHROMEOS)
+#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
 const int kLowestRendererOomScore = 300;
 const int kHighestRendererOomScore = 1000;
 
