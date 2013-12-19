--- lmove.c.orig	Fri May 23 08:16:38 1997
+++ lmove.c	Mon Aug 25 16:43:04 1997
@@ -27,6 +27,7 @@
 #include <sys/stat.h>
 #include <errno.h>
 #include <signal.h>
+#include <sys/syslimits.h>
 
 #include "suck_config.h"
 #include "both.h"
