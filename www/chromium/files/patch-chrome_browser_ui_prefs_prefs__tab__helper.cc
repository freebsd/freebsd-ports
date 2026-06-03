--- chrome/browser/ui/prefs/prefs_tab_helper.cc.orig	2026-04-09 06:05:42 UTC
+++ chrome/browser/ui/prefs/prefs_tab_helper.cc
@@ -65,7 +65,7 @@
 #endif
 
 #if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_ANDROID) || BUILDFLAG(ENABLE_DESKTOP_ANDROID_EXTENSIONS)
+    BUILDFLAG(IS_ANDROID) || BUILDFLAG(ENABLE_DESKTOP_ANDROID_EXTENSIONS) || BUILDFLAG(IS_BSD)
 // If a font name in prefs default values starts with a comma, consider it's a
 // comma-separated font list and resolve it to the first available font.
 #define PREFS_FONT_LIST 1
@@ -152,7 +152,7 @@ constexpr auto kFontDefaults = std::to_array<FontDefau
     {prefs::kWebKitFantasyFontFamily, IDS_FANTASY_FONT_FAMILY},
     {prefs::kWebKitMathFontFamily, IDS_MATH_FONT_FAMILY},
 #if BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || \
-    BUILDFLAG(IS_LINUX) || BUILDFLAG(ENABLE_DESKTOP_ANDROID_EXTENSIONS)
+    BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD) || BUILDFLAG(ENABLE_DESKTOP_ANDROID_EXTENSIONS)
     {prefs::kWebKitStandardFontFamilyJapanese,
      IDS_STANDARD_FONT_FAMILY_JAPANESE},
     {prefs::kWebKitFixedFontFamilyJapanese, IDS_FIXED_FONT_FAMILY_JAPANESE},
