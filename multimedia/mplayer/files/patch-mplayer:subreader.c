--- subreader.c.orig	Mon May 13 22:41:20 2002
+++ subreader.c	Tue Jun  4 22:54:33 2002
@@ -18,11 +18,7 @@
 #define ERR ((void *) -1)
 
 #ifdef USE_ICONV
-#ifdef __FreeBSD__
-#include <giconv.h>
-#else
 #include <iconv.h>
-#endif
 char *sub_cp=NULL;
 #endif
 
