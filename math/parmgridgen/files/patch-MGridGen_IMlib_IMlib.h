--- MGridGen/IMlib/IMlib.h.orig	2010-02-24 15:22:46.000000000 +0600
+++ MGridGen/IMlib/IMlib.h	2010-02-24 15:22:57.000000000 +0600
@@ -43,7 +43,7 @@
 #ifdef DMALLOC
 #include <dmalloc.h>
 #else
-#include <malloc.h>
+#include <stdlib.h>
 #endif
 
 /*************************************************************************
