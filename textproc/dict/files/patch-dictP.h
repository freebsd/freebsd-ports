--- dictP.h.orig	Wed Nov 26 08:11:05 2003
+++ dictP.h	Wed Nov 26 08:11:29 2003
@@ -108,11 +108,7 @@
 typedef unsigned int wchar_t;
 #endif
 
-#if HAVE_MBSTATE_T
-#include <wchar.h>
-#else
 typedef char mbstate_t;
-#endif
 
 #if !HAVE_WCRTOMB
 extern size_t wcrtomb (char *s, wchar_t wc, mbstate_t *ps);
