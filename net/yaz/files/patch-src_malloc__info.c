--- src/malloc_info.c.orig	2016-10-05 20:17:14 UTC
+++ src/malloc_info.c
@@ -12,7 +12,7 @@
 #include <config.h>
 #endif
 
-#include <malloc.h>
+#include <stdlib.h>
 #include <stdio.h>
 
 #include <yaz/wrbuf.h>
