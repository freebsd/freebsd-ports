--- mplayerxp/nls/recode.c.orig	Sat Feb 11 03:39:53 2006
+++ mplayerxp/nls/recode.c	Sun Oct  1 22:34:34 2006
@@ -3,11 +3,7 @@
 #include <stdlib.h>
 #include <errno.h>
 #ifdef USE_ICONV
-#ifdef __FreeBSD__
-#include <giconv.h>
-#else
 #include <iconv.h>
-#endif
 #endif
 #include "nls_msg.h"
 #include "./nls.h"
