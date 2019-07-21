--- src/common/track_script.c.orig	2019-06-10 01:59:00 UTC
+++ src/common/track_script.c
@@ -36,6 +36,7 @@
 
 #include <signal.h>
 #include <sys/time.h>
+#include <sys/wait.h>
 
 #include "src/common/macros.h"
 #include "src/common/xmalloc.h"
