--- Connection.cpp.orig	Fri Apr  2 18:55:19 2004
+++ Connection.cpp	Sat Apr 17 23:12:22 2004
@@ -27,6 +27,8 @@
 #include <config.h>
 #endif
 
+#include <sys/types.h>
+
 #include <string.h>
 #include <stdlib.h>
 #include <netdb.h>
