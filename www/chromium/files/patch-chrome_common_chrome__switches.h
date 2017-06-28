--- chrome/common/chrome_switches.h.orig	2017-06-05 19:03:03 UTC
+++ chrome/common/chrome_switches.h
@@ -352,7 +352,7 @@ extern const char kAllowNaClSocketAPI[];
 extern const char kEnableWaylandServer[];
 #endif
 
-#if defined(OS_WIN) || defined(OS_LINUX)
+#if defined(OS_WIN) || defined(OS_LINUX) || defined(OS_BSD)
 extern const char kDisableInputImeAPI[];
 extern const char kEnableInputImeAPI[];
 #endif
