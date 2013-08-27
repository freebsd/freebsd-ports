--- webkit/plugins/ppapi/usb_key_code_conversion.cc.orig	2013-08-18 21:36:48.000000000 +0300
+++ webkit/plugins/ppapi/usb_key_code_conversion.cc	2013-08-18 21:37:12.000000000 +0300
@@ -11,7 +11,8 @@
 namespace webkit {
 namespace ppapi {
 
-#if !defined(OS_LINUX) && !defined(OS_MACOSX) && !defined(OS_WIN)
+#if !defined(OS_LINUX) && !defined(OS_MACOSX) && !defined(OS_WIN) && \
+    !defined(OS_BSD)
 
 uint32_t UsbKeyCodeForKeyboardEvent(const WebKeyboardEvent& key_event) {
   return 0;
