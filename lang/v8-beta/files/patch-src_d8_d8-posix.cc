--- src/d8/d8-posix.cc.orig	2020-06-13 18:02:18 UTC
+++ src/d8/d8-posix.cc
@@ -4,6 +4,8 @@
 
 #include <errno.h>
 #include <fcntl.h>
+#include <sys/types.h>
+#include <netinet/in.h>
 #include <netinet/ip.h>
 #include <signal.h>
 #include <stdlib.h>
@@ -12,7 +14,6 @@
 #include <sys/socket.h>
 #include <sys/stat.h>
 #include <sys/time.h>
-#include <sys/types.h>
 #include <sys/wait.h>
 #include <unistd.h>
 
