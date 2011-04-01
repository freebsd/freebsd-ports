--- ./third_party/icu/public/common/unicode/umachine.h.orig	2010-12-16 02:34:25.000000000 +0100
+++ ./third_party/icu/public/common/unicode/umachine.h	2010-12-20 20:15:08.000000000 +0100
@@ -49,6 +49,8 @@
 #   include "unicode/pmac.h"
 #elif defined(__linux__)
 #   include "unicode/plinux.h"
+#elif defined(__FreeBSD__)
+#   include "unicode/pfreebsd.h"
 #else
 #   include "unicode/platform.h"
 #endif
