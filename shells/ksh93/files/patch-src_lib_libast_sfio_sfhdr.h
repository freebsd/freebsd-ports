
$FreeBSD$

--- src/lib/libast/sfio/sfhdr.h.orig	Tue Dec  4 21:58:08 2001
+++ src/lib/libast/sfio/sfhdr.h	Tue Dec  4 21:58:52 2001
@@ -521,8 +521,8 @@
 #define SFSETLOCALE(dp,tp) \
 	do if (*(dp) == 0) { \
 		Lc_numeric_t*	lv = (Lc_numeric_t*)LCINFO(AST_LC_NUMERIC)->data; \
-		*(dp) = lv->decimal; \
-		*(tp) = lv->thousand; \
+		*(dp) = lv ? lv->decimal : '.'; \
+		*(tp) = lv ? lv->thousand: '\0'; \
 	} while (0)
 #else
 #if _lib_locale
