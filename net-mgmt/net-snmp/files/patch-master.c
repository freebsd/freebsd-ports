--- agent/mibgroup/agentx/master.c.orig	Mon Jan 24 09:16:00 2005
+++ agent/mibgroup/agentx/master.c	Mon Jan 24 09:16:21 2005
@@ -39,10 +39,6 @@
 #endif
 #include <errno.h>
 
-#if HAVE_DMALLOC_H
-#include <dmalloc.h>
-#endif
-
 #if HAVE_UNISTD_H
 #include <unistd.h>
 #endif
