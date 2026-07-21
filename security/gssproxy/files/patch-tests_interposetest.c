--- tests/interposetest.c.orig	2022-07-26 10:17:29 UTC
+++ tests/interposetest.c
@@ -3,6 +3,7 @@
 #include "config.h"
 #include <stdlib.h>
 #include <unistd.h>
+#include <signal.h>
 #include <fcntl.h>
 #include <sys/types.h>
 #include <sys/stat.h>
