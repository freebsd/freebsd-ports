--- gnulib/xvasprintf.c.orig	Fri Aug 11 17:26:52 2006
+++ gnulib/xvasprintf.c	Fri Aug 11 17:27:31 2006
@@ -37,6 +37,10 @@
 # define EOVERFLOW E2BIG
 #endif
 
+#ifndef gl_va_copy
+# define gl_va_copy(a,b) (a) = (b)
+#endif
+
 static inline char *
 xstrcat (size_t argcount, va_list args)
 {
