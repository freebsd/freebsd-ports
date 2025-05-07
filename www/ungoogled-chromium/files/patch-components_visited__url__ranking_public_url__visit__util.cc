--- components/visited_url_ranking/public/url_visit_util.cc.orig	2025-05-06 12:23:00 UTC
+++ components/visited_url_ranking/public/url_visit_util.cc
@@ -67,7 +67,7 @@ PlatformType GetPlatformInput() {
   return PlatformType::kWindows;
 #elif BUILDFLAG(IS_MAC)
   return PlatformType::kMac;
-#elif BUILDFLAG(IS_LINUX)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   return PlatformType::kLinux;
 #elif BUILDFLAG(IS_IOS)
   return PlatformType::kIos;
