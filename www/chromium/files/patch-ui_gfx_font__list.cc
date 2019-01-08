--- ui/gfx/font_list.cc.orig	2018-12-03 21:18:06.000000000 +0100
+++ ui/gfx/font_list.cc	2018-12-15 20:17:39.591084000 +0100
@@ -24,7 +24,7 @@
 bool g_default_impl_initialized = false;
 
 bool IsFontFamilyAvailable(const std::string& family, SkFontMgr* fontManager) {
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
   return !!fontManager->legacyMakeTypeface(family.c_str(), SkFontStyle());
 #else
   sk_sp<SkFontStyleSet> set(fontManager->matchFamily(family.c_str()));
