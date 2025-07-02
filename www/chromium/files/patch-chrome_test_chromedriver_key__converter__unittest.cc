--- chrome/test/chromedriver/key_converter_unittest.cc.orig	2025-07-02 06:08:04 UTC
+++ chrome/test/chromedriver/key_converter_unittest.cc
@@ -248,7 +248,7 @@ TEST(KeyConverter, ToggleModifiers) {
   CheckEventsReleaseModifiers(keys, key_events);
 }
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 // Fails on bots: crbug.com/174962
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
