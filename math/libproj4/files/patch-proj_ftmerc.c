--- ./proj_ftmerc.c.orig	2008-11-20 18:40:28.000000000 +0100
+++ ./proj_ftmerc.c	2014-10-16 21:31:30.000000000 +0200
@@ -31,6 +31,10 @@
 #define PROJ_LIB__
 #include	<lib_proj.h>
 #include <complex.h>
+#include <sys/param.h>
+#if defined(__FreeBSD__) && (__FreeBSD_version < 1000034)
+# include <missing_complex.h>
+#endif
 PROJ_HEAD(ftmerc, "French Transverse Mercator") "\n\tCyl, Ell";
 
 /* forward series constants */
