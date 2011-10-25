--- third_party/leveldatabase/env_chromium.cc.orig	2011-10-09 00:31:40.173746519 +0300
+++ third_party/leveldatabase/env_chromium.cc	2011-10-09 00:33:07.446263098 +0300
@@ -30,7 +30,8 @@
 #include "base/win/win_util.h"
 #endif
 
-#if defined(OS_MACOSX) || defined(OS_WIN) || defined(OS_ANDROID)
+#if defined(OS_MACOSX) || defined(OS_WIN) || defined(OS_ANDROID) \
+  || defined(OS_FREEBSD)
 // The following are glibc-specific
 namespace {
 
