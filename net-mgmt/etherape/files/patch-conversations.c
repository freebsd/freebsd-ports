--- src/conversations.c.orig	Fri Jul  6 11:47:09 2001
+++ src/conversations.c	Fri Jul  6 11:47:18 2001
@@ -21,6 +21,7 @@
 #include <config.h>
 #endif
 
+#include <sys/types.h>
 #include <netinet/in.h>
 #include "globals.h"
 #include "conversations.h"
