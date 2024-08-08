--- components/visited_url_ranking/public/url_visit_util.cc.orig	2024-07-30 11:12:21 UTC
+++ components/visited_url_ranking/public/url_visit_util.cc
@@ -54,7 +54,7 @@ PlatformType GetPlatformInput() {
   return PlatformType::kWindows;
 #elif BUILDFLAG(IS_MAC)
   return PlatformType::kMac;
-#elif BUILDFLAG(IS_LINUX)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   return PlatformType::kLinux;
 #elif BUILDFLAG(IS_IOS)
   return PlatformType::kIos;
