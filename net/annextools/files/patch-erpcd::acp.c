--- erpcd/acp.c.orig	Tue Dec  2 14:49:05 1997
+++ erpcd/acp.c	Thu Sep 18 20:10:32 2003
@@ -40,10 +40,6 @@
 #include <signal.h>
 #include <errno.h>
 
-#ifndef _WIN32
-extern int sys_nerr;
-#endif /* not _WIN32 */
-
 #include "../libannex/api_if.h"
 #include "../libannex/srpc.h"
 #include "../inc/courier/courier.h"
