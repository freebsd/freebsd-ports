--- daemon/prompt/gkd-prompt.c.orig	2009-12-21 19:17:13.000000000 -0500
+++ daemon/prompt/gkd-prompt.c	2009-12-21 19:17:23.000000000 -0500
@@ -21,6 +21,8 @@
 
 #include "config.h"
 
+#include <sys/wait.h>
+
 #include "gkd-prompt.h"
 #include "gkd-prompt-marshal.h"
 #include "gkd-prompt-util.h"
