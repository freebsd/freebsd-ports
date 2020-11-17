diff --git src/tests/cwrap/test_server.c src/tests/cwrap/test_server.c
index 85ecb7f74..a2ddc595f 100644
--- src/tests/cwrap/test_server.c
+++ src/tests/cwrap/test_server.c
@@ -23,6 +23,7 @@
 #include <sys/types.h>
 #include <sys/stat.h>
 #include <fcntl.h>
+#include <signal.h>
 
 #include <popt.h>
 #include "util/util.h"
