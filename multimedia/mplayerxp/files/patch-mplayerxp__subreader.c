--- mplayerxp/subreader.c.orig	Sat Feb 11 03:39:49 2006
+++ mplayerxp/subreader.c	Sun Oct  1 21:15:14 2006
@@ -19,11 +19,7 @@
 #define ERR ((void *) -1)
 
 #ifdef USE_ICONV
-#ifdef __FreeBSD__
-#include <giconv.h>
-#else
 #include <iconv.h>
-#endif
 #endif
 char *sub_cp=NULL;
 
