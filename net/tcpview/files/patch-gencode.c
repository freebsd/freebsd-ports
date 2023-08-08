--- gencode.c.orig	1993-04-22 20:40:01 UTC
+++ gencode.c
@@ -36,7 +36,7 @@ static char rcsid[] =
 #include <net/bpf.h>
 
 #ifdef TCPVIEW
-#include <varargs.h>
+#include <stdarg.h>
 #include <setjmp.h>
 static jmp_buf env;
 #define error parse_error
@@ -97,10 +97,15 @@ static int cur_chunk;
 static int cur_chunk;
 
 #ifdef TCPVIEW
-void parse_error(va_alist)
-     va_dcl
+extern eprintv(char *cp, va_list ap);
+
+void parse_error(char *cp, ...)
 {
-  eprint(va_alist);
+  va_list ap;
+
+  va_start(ap, cp);
+  eprintv(cp, ap);
+  va_end(ap);
   longjmp(env,1);
 }
 #endif
