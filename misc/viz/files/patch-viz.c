--- viz.c.orig	1995-04-14 13:30:56 UTC
+++ viz.c
@@ -55,14 +55,19 @@
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
+
+MEMP rootlist;
 
 char *prog;
 struct Format Fmt = {
