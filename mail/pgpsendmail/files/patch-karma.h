--- karma.h.orig	1994-10-15 17:41:33.000000000 +0000
+++ karma.h
@@ -60,11 +60,7 @@ typedef unsigned long uaddr;
  *     ERRNO_TYPE                                            *
  *-----------------------------------------------------------*/
 
-#ifdef __ZTC__
-#define ERRNO_TYPE extern volatile int
-#else
-#define ERRNO_TYPE extern int
-#endif
+#define ERRNO_TYPE int
 
 /*-----------------------------------------------------------*
  *     PI Definitions                                        *
