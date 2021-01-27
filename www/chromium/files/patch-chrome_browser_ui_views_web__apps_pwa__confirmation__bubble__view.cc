--- chrome/browser/ui/views/web_apps/pwa_confirmation_bubble_view.cc.orig	2021-01-18 21:28:51 UTC
+++ chrome/browser/ui/views/web_apps/pwa_confirmation_bubble_view.cc
@@ -42,7 +42,7 @@
 
 namespace {
 
-#if defined(OS_WIN) || defined(OS_MAC) || defined(OS_LINUX) || \
+#if defined(OS_WIN) || defined(OS_MAC) || defined(OS_LINUX) || defined(OS_BSD) || \
     defined(OS_CHROMEOS)
 constexpr char kDeviceTypeForCheckbox[] = "computer";
 #else
