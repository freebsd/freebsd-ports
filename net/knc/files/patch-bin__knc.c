--- ./bin/knc.c.orig	2013-02-09 21:09:13.000000000 +0400
+++ ./bin/knc.c	2013-02-09 21:09:29.000000000 +0400
@@ -47,7 +47,7 @@
 #include <time.h>
 #include <unistd.h>
 
-#include "gssapi/gssapi.h"
+#include "config.h"
 #include "gssstdio.h"
 #include "knc.h"
 
