--- error.c.orig	Sat Apr 28 14:08:54 2007
+++ error.c	Sat Apr 28 14:17:12 2007
@@ -5,6 +5,9 @@
 #include <sys/types.h>
 #include <signal.h>
 #include <syslog.h>
+#include <sys/param.h>
+#include <libutil.h>
+#include "anna.h"
