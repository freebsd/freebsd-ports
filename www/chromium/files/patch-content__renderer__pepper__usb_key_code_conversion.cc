--- content/renderer/pepper/usb_key_code_conversion.cc.orig	2013-09-03 23:00:20.220628554 +0300
+++ content/renderer/pepper/usb_key_code_conversion.cc	2013-09-03 23:02:18.736631955 +0300
@@ -10,7 +10,7 @@
 
 namespace content {
 
-#if !defined(OS_LINUX) && !defined(OS_MACOSX) && !defined(OS_WIN)
+#if !((defined(OS_POSIX) && !defined(OS_ANDROID)) || defined(OS_WIN))
 
 uint32_t UsbKeyCodeForKeyboardEvent(const WebKeyboardEvent& key_event) {
   return 0;
