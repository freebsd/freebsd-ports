--- src/tests/cwrap/test_server.c.orig	2020-03-17 13:31:28 UTC
+++ src/tests/cwrap/test_server.c
@@ -23,6 +23,7 @@
 #include <sys/types.h>
 #include <sys/stat.h>
 #include <fcntl.h>
+#include <signal.h>
 
 #include <popt.h>
 #include "util/util.h"
