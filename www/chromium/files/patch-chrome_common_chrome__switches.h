--- chrome/common/chrome_switches.h.orig	2017-03-09 20:04:29 UTC
+++ chrome/common/chrome_switches.h
@@ -355,7 +355,7 @@ extern const char kAllowNaClSocketAPI[];
 extern const char kEnableWaylandServer[];
 #endif
 
-#if defined(OS_WIN) || defined(OS_LINUX)
+#if defined(OS_WIN) || defined(OS_LINUX) || defined(OS_BSD)
 extern const char kDisableInputImeAPI[];
 extern const char kEnableInputImeAPI[];
 #endif
