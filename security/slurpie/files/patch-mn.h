--- src/mn.h.orig	Sat Jan 30 13:09:01 1999
+++ src/mn.h	Sun Feb 13 19:13:32 2000
@@ -2,11 +2,12 @@
 #define _MN_H_
 
 /////////////////////////////////
-#include <stdio.h>
-#include <stdarg.h>
-#include <netinet/in.h>
 #include <sys/types.h>
 #include <sys/time.h>
+#include <sys/socket.h>
+#include <netinet/in.h>
+#include <stdio.h>
+#include <stdarg.h>
 
 
 /////////////////////////////////
