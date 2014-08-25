--- ./content/renderer/pepper/usb_key_code_conversion.cc.orig	2014-08-20 21:02:43.000000000 +0200
+++ ./content/renderer/pepper/usb_key_code_conversion.cc	2014-08-22 15:06:26.000000000 +0200
@@ -10,7 +10,7 @@
 
 namespace content {
 
-#if !defined(OS_LINUX) && !defined(OS_MACOSX) && !defined(OS_WIN)
+#if !((defined(OS_POSIX) && !defined(OS_ANDROID)) || defined(OS_WIN))
 
 uint32_t UsbKeyCodeForKeyboardEvent(const WebKeyboardEvent& key_event) {
   return 0;
