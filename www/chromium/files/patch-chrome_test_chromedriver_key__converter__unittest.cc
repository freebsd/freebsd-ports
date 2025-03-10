--- chrome/test/chromedriver/key_converter_unittest.cc.orig	2025-02-19 07:43:18 UTC
+++ chrome/test/chromedriver/key_converter_unittest.cc
@@ -252,7 +252,7 @@ TEST(KeyConverter, ToggleModifiers) {
   CheckEventsReleaseModifiers(keys, key_events);
 }
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 // Fails on bots: crbug.com/174962
 #define MAYBE_AllEnglishKeyboardSymbols DISABLED_AllEnglishKeyboardSymbols
 #else
@@ -310,7 +310,7 @@ TEST(KeyConverter, AllEnglishKeyboardTextChars) {
 TEST(KeyConverter, AllSpecialWebDriverKeysOnEnglishKeyboard) {
   ui::ScopedKeyboardLayout keyboard_layout(ui::KEYBOARD_LAYOUT_ENGLISH_US);
   const auto kTextForKeys = std::to_array<char>({
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
       0,   0,   0,   0,   '\t', 0,   '\r', '\r', 0,   0,   0,   0,   0,
 #else
       0,   0,   0,   0,   0,   0,   '\r', '\r', 0,   0,   0,   0,   0,
