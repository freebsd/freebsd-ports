--- chrome/test/chromedriver/key_converter_unittest.cc.orig	2022-02-28 16:54:41 UTC
+++ chrome/test/chromedriver/key_converter_unittest.cc
@@ -246,7 +246,7 @@ TEST(KeyConverter, ToggleModifiers) {
   CheckEventsReleaseModifiers(keys, key_events);
 }
 
-#if defined(OS_LINUX) || defined(OS_CHROMEOS)
+#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
 // Fails on bots: crbug.com/174962
 #define MAYBE_AllEnglishKeyboardSymbols DISABLED_AllEnglishKeyboardSymbols
 #else
@@ -303,7 +303,7 @@ TEST(KeyConverter, AllEnglishKeyboardTextChars) {
 TEST(KeyConverter, AllSpecialWebDriverKeysOnEnglishKeyboard) {
   ui::ScopedKeyboardLayout keyboard_layout(ui::KEYBOARD_LAYOUT_ENGLISH_US);
   const char kTextForKeys[] = {
-#if defined(OS_LINUX) || defined(OS_CHROMEOS)
+#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_LINUX)
       0, 0, 0, 0, '\t', 0, '\r', '\r', 0, 0, 0, 0, 0,
 #else
       0, 0, 0, 0, 0, 0, '\r', '\r', 0, 0, 0, 0, 0,
