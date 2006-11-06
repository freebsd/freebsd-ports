--- ./server/drivers/CFontz633io.c.orig	Mon Oct 16 22:26:21 2006
+++ ./server/drivers/CFontz633io.c	Mon Oct 16 22:28:58 2006
@@ -49,12 +49,9 @@
 
 #include "config.h"
 
-#if defined(HAVE_SYS_SELECT_H)
-# include <sys/select.h>
-#else
-# include <sys/time.h>
-# include <sys/types.h>
-#endif /* defined(HAVE_SYS_SELECT_H) */
+#include <sys/select.h>
+#include <sys/time.h>
+#include <sys/types.h>
 
 #include "CFontz633io.h"
 
