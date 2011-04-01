--- chrome/common/native_web_keyboard_event.h.orig	2011-03-20 22:02:04.188736136 +0200
+++ chrome/common/native_web_keyboard_event.h	2011-03-20 22:02:04.394737178 +0200
@@ -60,7 +60,7 @@
   // Currently, it's only used by Linux and Mac ports.
   bool skip_in_browser;
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_FREEBSD)
   // True if the key event matches an edit command. In order to ensure the edit
   // command always work in web page, the browser should not pre-handle this key
   // event as a reserved accelerator. See http://crbug.com/54573
