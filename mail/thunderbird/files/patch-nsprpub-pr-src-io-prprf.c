--- nsprpub/pr/src/io/prprf.c.orig	Mon Mar  8 22:18:19 2004
+++ nsprpub/pr/src/io/prprf.c	Mon May  3 13:00:27 2004
@@ -51,7 +51,10 @@
 ** Note: on some platforms va_list is defined as an array,
 ** and requires array notation.
 */
-#if (defined(LINUX) && defined(__x86_64__))
+#if defined(__amd64__)
+#include <stdarg.h>
+#define VARARGS_ASSIGN(foo, bar) va_copy((foo), (bar))
+#elif (defined(LINUX) && defined(__x86_64__))
 #define VARARGS_ASSIGN(foo, bar) __va_copy((foo), (bar))
 #elif (defined(LINUX) && defined(__powerpc__)) || \
     (defined(LINUX) && defined(__s390__)) || \
