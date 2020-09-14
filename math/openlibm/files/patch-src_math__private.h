--- src/math_private.h.orig	2018-06-18 21:22:47 UTC
+++ src/math_private.h
@@ -203,10 +203,10 @@ do {								\
 } while (0)
 
 
+#ifndef __FreeBSD__
 //VBS
 #define	STRICT_ASSIGN(type, lval, rval)	((lval) = (rval))
-
-/* VBS
+#else
 #ifdef FLT_EVAL_METHOD
 // Attempt to get strict C99 semantics for assignment with non-C99 compilers.
 #if FLT_EVAL_METHOD == 0 || __GNUC__ == 0
@@ -215,7 +215,7 @@ do {								\
 #define	STRICT_ASSIGN(type, lval, rval) do {	\
 	volatile type __lval;			\
 						\
-	if (sizeof(type) >= sizeof(double))	\
+	if (sizeof(type) >= sizeof(long double))	\
 		(lval) = (rval);		\
 	else {					\
 		__lval = (rval);		\
@@ -224,7 +224,7 @@ do {								\
 } while (0)
 #endif
 #endif
-*/
+#endif
 
 /*
  * Common routine to process the arguments to nan(), nanf(), and nanl().
