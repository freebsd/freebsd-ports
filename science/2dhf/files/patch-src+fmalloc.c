--- src/fmalloc.c.orig	Thu Jul 24 17:32:52 2003
+++ src/fmalloc.c	Thu Jul 24 17:33:22 2003
@@ -15,7 +15,11 @@
 
 #include <stdio.h>
 #include <sys/types.h>
+#ifdef __FreeBSD__ 
+#include <stdlib.h>
+#else
 #include <malloc.h>
+#endif
 
 /*
       bv:     is an integer to contain the address to the reserved
