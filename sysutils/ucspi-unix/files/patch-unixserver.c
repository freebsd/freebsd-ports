--- unixserver.c.orig	Tue Sep 23 16:32:51 2003
+++ unixserver.c	Tue Sep 23 16:33:34 2003
@@ -7,7 +7,7 @@
 #include <sys/un.h>
 #include <sys/wait.h>
 #include <unistd.h>
-#include <sysdeps.h>
+#include </usr/local/include/bglibs/sysdeps.h>
 
 extern void setup_env(int, const char*);
 
