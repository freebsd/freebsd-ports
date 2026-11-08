--- src/brave/chromium_src/components/feature_engagement/public/feature_list.h.orig	2026-06-01 00:00:00 UTC
+++ src/brave/chromium_src/components/feature_engagement/public/feature_list.h
@@ -15,7 +15,7 @@
 // variation params are defined, and allows us to define Brave-specific IPH
 // variation params. A patch is necessary because the DEFINE_VARIATION_PARAM
 // macro is undef'ed at the end of the header file.
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD))
 #define BRAVE_FEATURE_ENGAGEMENT_VARIATION_PARAMS           \
   DEFINE_VARIATION_PARAM(kIPHBraveShieldsInPageInfoFeature, \
                          "IPH_BraveShieldsInPageInfo");
@@ -26,7 +26,7 @@
 // BRAVE_FEATURE_ENGAGEMENT_VARIATION_ENTRIES is patched in at the start of the
 // kIPHDemoModeChoiceVariations array, and allows us to add Brave-specific IPH
 // variation entries to the array.
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD))
 #define BRAVE_FEATURE_ENGAGEMENT_VARIATION_ENTRIES \
   VARIATION_ENTRY(kIPHBraveShieldsInPageInfoFeature),
 #else
