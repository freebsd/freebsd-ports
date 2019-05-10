--- core/src/include/baconfig.h	2019-05-10 14:32:06.160940000 -0500
+++ core/src/include/baconfig.h	2019-05-10 14:32:32.142847000 -0500
@@ -120,11 +120,11 @@
       #define N_(s) (s)
    #endif /* N_ */
 #else /* !ENABLE_NLS */
+   #include <locale.h>
    #undef _
    #undef N_
    #undef textdomain
    #undef bindtextdomain
-   #undef setlocale
 
    #ifndef _
       #define _(s) (s)
@@ -137,9 +137,6 @@
    #endif
    #ifndef bindtextdomain
       #define bindtextdomain(p, d)
-   #endif
-   #ifndef setlocale
-      #define setlocale(p, d)
    #endif
 #endif /* ENABLE_NLS */
 
