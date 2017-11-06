--- build-aux/yuck.c.orig	2016-12-13 05:12:37 UTC
+++ build-aux/yuck.c
@@ -61,6 +61,8 @@
 #include <fcntl.h>
 #include <sys/wait.h>
 #include <sys/stat.h>
+#include <sys/types.h>
+#include <sys/sysctl.h>
 #include <time.h>
 #if defined WITH_SCMVER
 # include <yuck-scmver.h>
