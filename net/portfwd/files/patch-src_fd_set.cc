--- src/fd_set.cc.orig	Mon Sep 12 14:37:15 2005
+++ src/fd_set.cc	Mon Sep 12 14:38:03 2005
@@ -3,9 +3,8 @@
  */
 
 
-#include <ulimit.h>
-#include <sys/select.h>
 #include <sys/types.h>
+#include <sys/select.h>
 #include <unistd.h>
 #include <sys/time.h>
 #include <sys/resource.h>
