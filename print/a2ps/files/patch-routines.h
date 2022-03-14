--- lib/routines.h.orig	1999-10-18 20:24:41 UTC
+++ lib/routines.h
@@ -255,7 +255,8 @@ FILE * xwpopen PARAMS ((const char * command));
 /* If _STR_ is not defined, give it a tempname in _TMPDIR_ */
 #define tempname_ensure(Str)				\
 do {							\
-  (Str) = (Str) ? (Str) : tempnam (NULL, "a2_");	\
+  (Str) = (Str) ? (Str) : safe_tempnam("a2_");	\
 } while (0)
+char * safe_tempnam(const char *);
 
 #endif
