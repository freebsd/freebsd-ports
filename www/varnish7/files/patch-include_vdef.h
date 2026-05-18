--- include/vdef.h.orig	2025-08-20 12:50:25 UTC
+++ include/vdef.h
@@ -255,6 +255,12 @@ int __llvm_gcov_flush(void);
 #  endif
 #endif
 
+#if __has_builtin(__builtin_memcmp)
+#  define vmemcmp(s1, s2, n) __builtin_memcmp(s1, s2, n)
+#else
+#  define vmemcmp(s1, s2, n) memcmp(s1, s2, n)
+#endif
+
 #ifndef v_counted_by_
 #  define v_counted_by_(field)
 #endif
@@ -277,6 +283,7 @@ typedef struct {
 #define Tlen(t)		(pdiff((t).b, (t).e))
 #define Tstr(s)		(/*lint -e(446)*/ (txt){(s), (s) + strlen(s)})
 #define Tstrcmp(t, s)	(strncmp((t).b, (s), Tlen(t)))
+#define Tstreq(t, s)	(Tlen(t) == strlen(s) && !vmemcmp((t).b, (s), Tlen(t)))
 #define Tforeach(c, t)	for ((c) = (t).b; (c) < (t).e; (c)++)
 
 /* #3020 dummy definitions until PR is merged*/
