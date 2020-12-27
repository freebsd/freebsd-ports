--- core/src/include/baconfig.h	2020-02-04 15:53:01.627766000 -0500
+++ core/src/include/baconfig.h	2020-02-04 15:53:34.762711000 -0500
@@ -119,11 +119,11 @@
 #define N_(s) (s)
 #endif /* N_ */
 #else  /* !ENABLE_NLS */
+#include <locale.h>
 #undef _
 #undef N_
 #undef textdomain
 #undef bindtextdomain
-#undef setlocale
 
 #ifndef _
 #define _(s) (s)
@@ -136,9 +136,6 @@
 #endif
 #ifndef bindtextdomain
 #define bindtextdomain(p, d)
-#endif
-#ifndef setlocale
-#define setlocale(p, d)
 #endif
 #endif /* ENABLE_NLS */
 
