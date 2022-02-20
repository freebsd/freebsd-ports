--- base/time/time.cc.orig	2022-02-07 13:39:41 UTC
+++ base/time/time.cc
@@ -4,7 +4,7 @@
 
 #include "base/time/time.h"
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
 // time.h is a widely included header and its size impacts build time.
 // Try not to raise this limit unless necessary. See
 // https://chromium.googlesource.com/chromium/src/+/HEAD/docs/wmax_tokens.md
