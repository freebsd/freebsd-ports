--- src/3rdparty/chromium/ui/gfx/font_list.cc.orig	2022-02-28 16:54:41 UTC
+++ src/3rdparty/chromium/ui/gfx/font_list.cc
@@ -27,7 +27,7 @@ base::LazyInstance<scoped_refptr<gfx::FontListImpl>>::
 bool g_default_impl_initialized = false;
 
 bool IsFontFamilyAvailable(const std::string& family, SkFontMgr* fontManager) {
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   return !!fontManager->legacyMakeTypeface(family.c_str(), SkFontStyle());
 #else
   sk_sp<SkFontStyleSet> set(fontManager->matchFamily(family.c_str()));
