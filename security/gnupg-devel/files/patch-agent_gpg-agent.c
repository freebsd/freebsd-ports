--- agent/gpg-agent.c.orig	Mon May  3 18:38:33 2004
+++ agent/gpg-agent.c	Mon May  3 18:39:16 2004
@@ -37,6 +37,9 @@
 # include <pth.h>
 #endif
 
+#include <sys/types.h>
+#include <sys/stat.h>
+
 #define JNLIB_NEED_LOG_LOGV
 #include "agent.h"
 #include <assuan.h> /* malloc hooks */
