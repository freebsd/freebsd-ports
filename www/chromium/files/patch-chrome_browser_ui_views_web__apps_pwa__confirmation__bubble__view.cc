--- chrome/browser/ui/views/web_apps/pwa_confirmation_bubble_view.cc.orig	2020-11-16 14:24:34 UTC
+++ chrome/browser/ui/views/web_apps/pwa_confirmation_bubble_view.cc
@@ -34,7 +34,7 @@
 
 namespace {
 
-#if defined(OS_WIN) || defined(OS_MAC) || defined(OS_LINUX) || \
+#if defined(OS_WIN) || defined(OS_MAC) || defined(OS_LINUX) || defined(OS_BSD) || \
     defined(OS_CHROMEOS)
 constexpr char kDeviceTypeForCheckbox[] = "computer";
 #else
