--- image/new.c.orig	Tue Aug 31 20:50:32 2004
+++ image/new.c	Fri Nov  5 13:53:17 2004
@@ -11,7 +11,7 @@
 #include "copyright.h"
 #include "image.h"
 
-#ifdef __APPLE__
+#if defined(__APPLE__) || defined(CSRG_BASED)
 #include <stdlib.h>
 #else
 #include <malloc.h>
