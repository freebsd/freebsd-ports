--- src/3rdparty/chromium/third_party/blink/common/privacy_budget/active_sampling.cc.orig	2022-08-31 12:19:35 UTC
+++ src/3rdparty/chromium/third_party/blink/common/privacy_budget/active_sampling.cc
@@ -24,7 +24,7 @@ namespace blink {
 bool IdentifiabilityActiveSampler::IsFontFamilyAvailable(const char* family,
                                                          SkFontMgr* fm) {
   base::ScopedAllowBaseSyncPrimitives allow;
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   return !!fm->legacyMakeTypeface(family, SkFontStyle());
 #else
   sk_sp<SkFontStyleSet> set(fm->matchFamily(family));
