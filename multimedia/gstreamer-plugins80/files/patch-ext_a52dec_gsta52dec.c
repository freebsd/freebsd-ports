--- ext/a52dec/gsta52dec.c.orig	Sun Apr  6 18:58:19 2003
+++ ext/a52dec/gsta52dec.c	Sun Apr 20 13:16:28 2003
@@ -25,7 +25,7 @@
 
 #include <stdlib.h>
 
-#ifdef HAVE_STDINT_H
+#if defined(HAVE_STDINT_H) || defined(__FreeBSD__)
 #include <stdint.h>
 #else
 /* (Ronald) hacky... can't include stdint.h because it's not available
