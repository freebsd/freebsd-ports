--- src/brave/chromium_src/components/feature_engagement/public/feature_list.cc.orig	2026-06-01 00:00:00 UTC
+++ src/brave/chromium_src/components/feature_engagement/public/feature_list.cc
@@ -10,7 +10,7 @@
 
 // Replaces the first entry in the kAllFeatures array with that entry, plus any
 // additional entries for Brave-specific IPH features.
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD))
 #define kIPHDummyFeature kIPHDummyFeature, &kIPHBraveShieldsInPageInfoFeature
 #endif
 
