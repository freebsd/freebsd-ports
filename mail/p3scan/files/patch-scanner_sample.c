--- scanner_sample.c.orig	Fri Jul 29 10:08:05 2005
+++ scanner_sample.c	Fri Jul 29 10:08:37 2005
@@ -31,10 +31,10 @@
  */
 
 #include <stdio.h>
-#include <malloc.h>
 #include <sys/un.h>
 #include <sys/socket.h>
 
+#include <stdlib.h>
 
 /* we need p3scan.h */
 #include "p3scan.h"
