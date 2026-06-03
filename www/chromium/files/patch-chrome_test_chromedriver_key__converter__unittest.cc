--- chrome/test/chromedriver/key_converter_unittest.cc.orig	2026-03-13 06:02:14 UTC
+++ chrome/test/chromedriver/key_converter_unittest.cc
@@ -248,7 +248,7 @@ TEST(KeyConverter, ToggleModifiers) {
   CheckEventsReleaseModifiers(keys, key_events);
 }
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 // Fails on bots: crbug.com/40301345
 #define MAYBE_AllEnglishKeyboardSymbols DISABLED_AllEnglishKeyboardSymbols
 #else
@@ -306,7 +306,7 @@ TEST(KeyConverter, AllEnglishKeyboardTextChars) {
 TEST(KeyConverter, AllSpecialWebDriverKeysOnEnglishKeyboard) {
   ui::ScopedKeyboardLayout keyboard_layout(ui::KEYBOARD_LAYOUT_ENGLISH_US);
   const auto kTextForKeys = std::to_array<char>({
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
       0,   0,   0,   0,   '\t', 0,   '\r', '\r', 0,   0,   0,   0,   0,
 #else
       0,   0,   0,   0,   0,   0,   '\r', '\r', 0,   0,   0,   0,   0,
