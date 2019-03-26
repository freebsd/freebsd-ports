--- Xvnc/include/Xos.h.orig	2000-06-11 12:00:51 UTC
+++ Xvnc/include/Xos.h
@@ -151,7 +151,6 @@ extern int sys_nerr;
 #endif /* X_NOT_POSIX else */
 
 #ifdef CSRG_BASED
-#include <stdlib.h>
 #include <unistd.h>
 #endif /* CSRG_BASED */
 
