--- src/kit/kit-spawn.c.orig	2007-12-23 00:22:49.000000000 -0500
+++ src/kit/kit-spawn.c	2007-12-23 00:22:58.000000000 -0500
@@ -40,6 +40,7 @@
 #include <unistd.h>
 #include <fcntl.h>
 #include <errno.h>
+#include <signal.h>
 
 #include <kit/kit.h>
 #include "kit-test.h"
