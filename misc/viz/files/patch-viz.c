--- viz.c.patched	Sat Mar  8 18:07:20 1997
+++ viz.c	Sat Mar  8 18:07:26 1997
@@ -55,14 +55,17 @@
 #define VIZ_MAIN
 #include "viz.h"
 
+#ifndef _SYS_ERRNO_H_
 extern errno;
 extern int sys_nerr;
 extern char *sys_errlist[];
+#endif
 
-
+#ifndef _STDLIB_H_
 extern char *malloc();
 extern optind, opterr;
 extern char *optarg;
+#endif
 
 char *prog;
 struct Format Fmt = {
