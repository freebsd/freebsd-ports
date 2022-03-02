--- chrome/test/chromedriver/keycode_text_conversion_unittest.cc.orig	2022-02-28 16:54:41 UTC
+++ chrome/test/chromedriver/keycode_text_conversion_unittest.cc
@@ -64,7 +64,7 @@ std::string ConvertKeyCodeToTextNoError(ui::KeyboardCo
 
 // TODO(crbug.com/1052397): Revisit the macro expression once build flag switch
 // of lacros-chrome is complete.
-#if defined(OS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS)
+#if defined(OS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS) || BUILDFLAG(IS_BSD)
 // Fails on bots: crbug.com/174962
 #define MAYBE_KeyCodeToText DISABLED_KeyCodeToText
 #else
@@ -101,7 +101,7 @@ TEST(KeycodeTextConversionTest, MAYBE_KeyCodeToText) {
 
 // TODO(crbug.com/1052397): Revisit the macro expression once build flag switch
 // of lacros-chrome is complete.
-#if defined(OS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS)
+#if defined(OS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS) || BUILDFLAG(IS_BSD)
 // Fails on bots: crbug.com/174962
 #define MAYBE_CharToKeyCode DISABLED_CharToKeyCode
 #else
