--- tests/anustart.c.orig	2024-01-05 16:03:10 UTC
+++ tests/anustart.c
@@ -64,6 +64,7 @@
 #include <fcntl.h>
 #include <errno.h>
 #include <limits.h>
+#include <signal.h>
 
 char const *progname;
 
