--- grammar/rainerscript.c.orig	2017-04-28 07:04:53 UTC
+++ grammar/rainerscript.c
@@ -35,6 +35,7 @@
 #include <sys/stat.h>
 #include <sys/types.h>
 #include <libestr.h>
+#include <unistd.h>
 #include "rsyslog.h"
 #include "rainerscript.h"
 #include "conf.h"
