--- extensions/browser/pref_names.h.orig	2021-12-16 15:11:30 UTC
+++ extensions/browser/pref_names.h
@@ -101,7 +101,7 @@ extern const char kToolbar[];
 // uninstalled/removed and should not be reloaded.
 extern const char kDeletedComponentExtensions[];
 
-#if defined(OS_WIN) || defined(OS_MAC) || defined(OS_LINUX)
+#if defined(OS_WIN) || defined(OS_MAC) || defined(OS_LINUX) || defined(OS_BSD)
 // A preference for whether Chrome Apps should be allowed. The default depends
 // on the ChromeAppsDeprecation feature flag, and this pref can extend support
 // for Chrome Apps by enterprise policy.
