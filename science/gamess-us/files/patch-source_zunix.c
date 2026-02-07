--- source/zunix.c.orig	2018-02-07 21:15:24 UTC
+++ source/zunix.c
@@ -92,7 +92,11 @@ void naptime_(nptime) int *nptime;
 #ifdef CRAYXD1
    
 #include <stdlib.h>
+#if defined(__FreeBSD__)
+#include <stdlib.h>
+#else
 #include <malloc.h>
+#endif
 #define FORTINT long
 
 FORTINT memget_(nwords) FORTINT *nwords;
@@ -296,7 +300,11 @@ void fdate(char *cht, int cht_len)
 #ifdef IBMPPC64
 
 #include <stdlib.h>
+#if defined(__FreeBSD__)
+#include <stdlib.h>
+#else
 #include <malloc.h>
+#endif
 
 #define FORTINT long
 
@@ -429,7 +437,11 @@ void fdate_(char *cht, int cht_len)
 #ifdef LINUX64
 
 #include <stdlib.h>
+#if defined(__FreeBSD__)
+#include <stdlib.h>
+#else
 #include <malloc.h>
+#endif
 
 #define FORTINT long
 
