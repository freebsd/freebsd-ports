--- tests/queue-test.c.orig	2016-04-29 23:36:09 UTC
+++ tests/queue-test.c
@@ -23,6 +23,8 @@
  * SOFTWARE.
  */
 
+#include "../config.h"
+
 #include <stdlib.h>
 #include <stdio.h>
 #include <stdbool.h>
@@ -30,6 +32,9 @@
 #include <sys/types.h>
 #include <sys/wait.h>
 #include <assert.h>
+#ifdef HAVE_SIGNAL_H
+#include <signal.h>
+#endif
 
 #include "wayland-client.h"
 #include "wayland-server.h"
