--- third_party/libjingle/source/talk/base/timing.cc.orig	2012-03-27 04:04:08.000000000 +0300
+++ third_party/libjingle/source/talk/base/timing.cc	2012-03-31 03:18:25.000000000 +0300
@@ -27,7 +27,7 @@
 
 #include "talk/base/timing.h"
 
-#if defined(POSIX)
+#if defined(POSIX) && !defined(FREEBSD)
 #define _POSIX_C_SOURCE 199506L
 #endif
 
