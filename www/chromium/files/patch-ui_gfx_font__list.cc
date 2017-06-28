--- ui/gfx/font_list.cc.orig	2017-06-05 19:03:30 UTC
+++ ui/gfx/font_list.cc
@@ -24,7 +24,7 @@ base::LazyInstance<scoped_refptr<gfx::FontListImpl>>::
 bool g_default_impl_initialized = false;
 
 bool IsFontFamilyAvailable(const std::string& family, SkFontMgr* fontManager) {
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
   sk_sp<SkTypeface> typeface(
       fontManager->legacyCreateTypeface(family.c_str(), SkFontStyle()));
   return typeface;
