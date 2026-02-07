--- src/zbuf/savemat_mod.c.orig	Tue Feb 28 21:04:21 2006
+++ src/zbuf/savemat_mod.c	Tue Feb 28 21:06:27 2006
@@ -23,7 +23,8 @@
  */
 #include <stdio.h>
 
-#ifdef ALPHA
+#if defined(ALPHA) || defined(__alpha__) || defined(__amd64__) || defined(___sparc64__) || defined(__ia64__)
+
 typedef struct {
      int type;   /* type */
      int mrows;  /* row dimension */
