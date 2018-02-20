--- chrome/browser/flag_descriptions.cc.orig	2017-12-15 02:04:09.000000000 +0100
+++ chrome/browser/flag_descriptions.cc	2017-12-24 01:21:43.685723000 +0100
@@ -2643,7 +2643,7 @@
 
 // Random platform combinations -----------------------------------------------
 
-#if defined(OS_WIN) || defined(OS_LINUX)
+#if defined(OS_WIN) || defined(OS_LINUX) || defined(OS_BSD)
 
 const char kEnableInputImeApiName[] = "Enable Input IME API";
 const char kEnableInputImeApiDescription[] =
