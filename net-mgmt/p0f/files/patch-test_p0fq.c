$FreeBSD$

--- test/p0fq.c.orig	Fri Oct 10 14:51:08 2003
+++ test/p0fq.c	Wed Dec 17 20:10:31 2003
@@ -14,6 +14,7 @@
 
   */
 
+#include <sys/types.h>
 #include <sys/socket.h>
 #include <stdio.h>
 #include <stdlib.h>
