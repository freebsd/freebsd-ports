--- src/calclib/Calculator.cc.orig	Thu Jul  8 12:00:01 2004
+++ src/calclib/Calculator.cc	Thu Jul  8 12:05:08 2004
@@ -27,9 +27,11 @@
 #include <unistd.h>
 #include <time.h>
 #include <sys/types.h>
+#include <sys/wait.h>
 #include <sys/stat.h>
+#include <sys/time.h>
+#include <sys/resource.h>
 #include <dirent.h>
-#include <wait.h>
 #include <queue>
 #include <stack>
 
