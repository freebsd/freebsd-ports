--- src/3rdparty/chromium/ui/gfx/font_list.cc.orig	2021-12-15 16:12:54 UTC
+++ src/3rdparty/chromium/ui/gfx/font_list.cc
@@ -24,7 +24,7 @@ bool IsFontFamilyAvailable(const std::string& family, 
 bool g_default_impl_initialized = false;
 
 bool IsFontFamilyAvailable(const std::string& family, SkFontMgr* fontManager) {
-#if defined(OS_LINUX) || defined(OS_CHROMEOS)
+#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
   return !!fontManager->legacyMakeTypeface(family.c_str(), SkFontStyle());
 #else
   sk_sp<SkFontStyleSet> set(fontManager->matchFamily(family.c_str()));
