--- src/fasthenry/savemat_mod.c.orig	Sat Feb 25 22:21:09 2006
+++ src/fasthenry/savemat_mod.c	Sat Feb 25 22:26:29 2006
@@ -57,7 +57,7 @@
  */
 #include <stdio.h>
 
-#ifdef ALPHA
+#ifdef ALPHA || defined(__alpha__) || defined(__amd64__) || defined(___sparc64__) || defined(__ia64__)
 typedef struct {
      int type;   /* type */
      int mrows;  /* row dimension */
