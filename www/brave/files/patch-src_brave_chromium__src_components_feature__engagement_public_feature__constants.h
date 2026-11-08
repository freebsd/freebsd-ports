--- src/brave/chromium_src/components/feature_engagement/public/feature_constants.h.orig	2026-06-01 00:00:00 UTC
+++ src/brave/chromium_src/components/feature_engagement/public/feature_constants.h
@@ -13,7 +13,7 @@
 
 namespace feature_engagement {
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD))
 // IPH for notifying users that Brave Shields settings have moved to Page Info.
 FEATURE_CONSTANTS_DECLARE_FEATURE(kIPHBraveShieldsInPageInfoFeature);
 #endif
