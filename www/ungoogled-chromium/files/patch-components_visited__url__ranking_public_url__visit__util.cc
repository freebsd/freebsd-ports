--- components/visited_url_ranking/public/url_visit_util.cc.orig	2024-10-27 06:40:35 UTC
+++ components/visited_url_ranking/public/url_visit_util.cc
@@ -66,7 +66,7 @@ PlatformType GetPlatformInput() {
   return PlatformType::kWindows;
 #elif BUILDFLAG(IS_MAC)
   return PlatformType::kMac;
-#elif BUILDFLAG(IS_LINUX)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   return PlatformType::kLinux;
 #elif BUILDFLAG(IS_IOS)
   return PlatformType::kIos;
