--- nsprpub/pr/src/io/prprf.c	Wed Feb 26 15:53:42 2003
+++ nsprpub/pr/src/io/prprf.c	Thu Oct 16 22:50:40 2003
@@ -52,5 +52,8 @@
 ** and requires array notation.
 */
-#if (defined(LINUX) && defined(__powerpc__)) || \
+#if defined(__amd64__)
+#include <stdarg.h>
+#define VARARGS_ASSIGN(foo, bar) va_copy((foo), (bar))
+#elif (defined(LINUX) && defined(__powerpc__)) || \
     (defined(LINUX) && defined(__s390__)) || \
     (defined(LINUX) && defined(__s390x__)) || \
