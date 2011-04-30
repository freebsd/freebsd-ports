--- third_party/icu/public/common/unicode/ptypes.h.orig	2011-04-19 21:44:48.515037943 +0300
+++ third_party/icu/public/common/unicode/ptypes.h	2011-04-19 21:44:58.365038712 +0300
@@ -26,6 +26,8 @@
 #   include "unicode/pmac.h"
 #elif defined(__linux__)
 #   include "unicode/plinux.h"
+#elif defined(__FreeBSD__)
+#   include "unicode/pfreebsd.h"
 #else
 #   include "unicode/platform.h"
 #endif
