--- third_party/icu/public/common/unicode/utypes.h.orig	2011-10-31 14:25:20.000000000 +0000
+++ third_party/icu/public/common/unicode/utypes.h	2011-10-31 18:11:55.000000000 +0000
@@ -32,7 +32,9 @@
 #ifndef UTYPES_H
 #define UTYPES_H
 
-
+#if defined(__FreeBSD__)
+#include <unicode/ptypes.h>
+#endif
 #include "unicode/umachine.h"
 #include "unicode/utf.h"
 #include "unicode/uversion.h"
