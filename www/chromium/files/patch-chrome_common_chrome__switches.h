--- chrome/common/chrome_switches.h.orig	2019-07-24 18:58:13 UTC
+++ chrome/common/chrome_switches.h
@@ -265,7 +265,7 @@ extern const char kAllowNaClFileHandleAPI[];
 extern const char kAllowNaClSocketAPI[];
 #endif
 
-#if defined(OS_LINUX) || defined(OS_MACOSX) || defined(OS_WIN)
+#if defined(OS_LINUX) || defined(OS_MACOSX) || defined(OS_WIN) || defined(OS_BSD)
 extern const char kEnableNewAppMenuIcon[];
 #endif
 
