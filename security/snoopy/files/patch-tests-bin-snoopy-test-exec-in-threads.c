--- tests/bin/snoopy-test-exec-in-threads.c.orig	2016-09-14 15:02:26 UTC
+++ tests/bin/snoopy-test-exec-in-threads.c
@@ -31,7 +31,7 @@
 #include <string.h>
 #include <sys/types.h>
 #include <unistd.h>
-#include <wait.h>
+#include <sys/wait.h>
 
 
 
