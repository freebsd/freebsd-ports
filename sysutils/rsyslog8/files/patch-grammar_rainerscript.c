--- grammar/rainerscript.c.orig	2014-12-02 10:15:16 UTC
+++ grammar/rainerscript.c
@@ -34,6 +34,7 @@
 #include <sys/stat.h>
 #include <sys/types.h>
 #include <libestr.h>
+#include <unistd.h>
 #include "rsyslog.h"
 #include "rainerscript.h"
 #include "conf.h"
