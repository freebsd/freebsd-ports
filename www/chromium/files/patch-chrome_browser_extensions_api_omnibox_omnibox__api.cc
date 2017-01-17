--- chrome/browser/extensions/api/omnibox/omnibox_api.cc.orig	2016-12-16 03:22:03.040835000 +0000
+++ chrome/browser/extensions/api/omnibox/omnibox_api.cc	2016-12-16 03:22:24.317714000 +0000
@@ -45,7 +45,7 @@
 // Pref key for omnibox.setDefaultSuggestion.
 const char kOmniboxDefaultSuggestion[] = "omnibox_default_suggestion";
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
 static const int kOmniboxIconPaddingLeft = 2;
 static const int kOmniboxIconPaddingRight = 2;
 #elif defined(OS_MACOSX)
