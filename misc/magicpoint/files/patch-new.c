--- image/new.c.orig	2004-09-01 03:50:32 UTC
+++ image/new.c
@@ -11,7 +11,7 @@
 #include "copyright.h"
 #include "image.h"
 
-#ifdef __APPLE__
+#if defined(__APPLE__) || defined(CSRG_BASED)
 #include <stdlib.h>
 #else
 #include <malloc.h>
