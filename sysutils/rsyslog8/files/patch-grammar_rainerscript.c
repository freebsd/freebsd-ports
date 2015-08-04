--- grammar/rainerscript.c.orig	2015-06-30 12:26:24 UTC
+++ grammar/rainerscript.c
@@ -35,6 +35,7 @@
 #include <sys/stat.h>
 #include <sys/types.h>
 #include <libestr.h>
+#include <unistd.h>
 #include "rsyslog.h"
 #include "rainerscript.h"
 #include "conf.h"
