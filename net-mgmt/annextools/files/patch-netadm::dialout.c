--- netadm/dialout.c	2008-01-27 16:29:09.000000000 +0100
+++ netadm/dialout.c	2008-01-27 16:36:23.000000000 +0100
@@ -66,14 +66,6 @@
 
 #include <stdio.h>
 
-#ifdef SYS_V
-#include <termio.h>
-#else
-#ifndef _WIN32
-#include <sgtty.h>
-#endif 
-#endif
-
 #include "../inc/courier/courier.h"
 #include "../inc/erpc/netadmp.h"
 
