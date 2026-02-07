--- include/BSdepend.h.orig	Tue Jul  8 21:10:10 1997
+++ include/BSdepend.h	Sun Oct  3 18:23:32 2004
@@ -16,6 +16,11 @@
 #define MPI_Aint int
 
 #include <stdio.h>
+
+#if defined(PARCH_freebsd)
+#include <stdlib.h>
+#endif
+
 #if defined(PARCH_sun4) && !defined(__cplusplus) && defined(_Gnu_)
 extern int fprintf(FILE*,const char*,...);
 extern void sscanf(char *,...);
