--- src/extra/tre/tre-internal.h.orig	2014-06-13 22:15:07 UTC
+++ src/extra/tre/tre-internal.h
@@ -17,6 +17,7 @@
 #include <wctype.h>
 #endif /* !HAVE_WCTYPE_H */
 
+#include <limits.h>
 #include <ctype.h>
 #include "tre.h"
 
@@ -48,7 +49,11 @@
 
 /* Wide characters. */
 typedef wint_t tre_cint_t;
+#if WCHAR_MAX <= INT_MAX
 #define TRE_CHAR_MAX WCHAR_MAX
+#else /* WCHAR_MAX > INT_MAX */
+#define TRE_CHAR_MAX INT_MAX
+#endif
 
 #ifdef TRE_MULTIBYTE
 #define TRE_MB_CUR_MAX MB_CUR_MAX
