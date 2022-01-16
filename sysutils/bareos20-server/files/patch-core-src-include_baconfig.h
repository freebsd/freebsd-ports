--- core/src/include/baconfig.h	2020-12-16 02:46:16.000000000 -0500
+++ core/src/include/baconfig.h	2020-12-23 22:47:40.992698000 -0500
@@ -103,11 +103,11 @@
 #    define N_(s) (s)
 #  endif /* N_ */
 #else    /* !ENABLE_NLS */
+#  include <locale.h>
 #  undef _
 #  undef N_
 #  undef textdomain
 #  undef bindtextdomain
-#  undef setlocale
 
 #  ifndef _
 #    define _(s) (s)
@@ -120,9 +120,6 @@
 #  endif
 #  ifndef bindtextdomain
 #    define bindtextdomain(p, d)
-#  endif
-#  ifndef setlocale
-#    define setlocale(p, d)
 #  endif
 #endif /* ENABLE_NLS */
 
