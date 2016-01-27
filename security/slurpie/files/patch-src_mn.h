--- src/mn.h.orig	1999-01-30 21:09:01 UTC
+++ src/mn.h
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
