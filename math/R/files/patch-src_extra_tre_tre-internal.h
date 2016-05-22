--- src/extra/tre/tre-internal.h.orig	2016-05-05 10:54:54 UTC
+++ src/extra/tre/tre-internal.h
@@ -17,6 +17,7 @@
 #include <wctype.h>
 #endif /* !HAVE_WCTYPE_H */
 
+#include <limits.h>
 #include <ctype.h>
 #include "tre.h"
 
@@ -47,7 +48,11 @@
 #ifdef TRE_WCHAR
 
 /* Wide characters. */
+#if WCHAR_MAX <= INT_MAX
 typedef wint_t tre_cint_t;
+#else /* WCHAR_MAX > INT_MAX */
+#define TRE_CHAR_MAX INT_MAX
+#endif
 /* Workaround problem seen on AIX, (2010 & 2015), e.g.,
     https://stat.ethz.ch/pipermail/r-devel/2015-October/071902.html
   WCHAR_MAX = UINT32_MAX on AIX and that is "not possible to work"
