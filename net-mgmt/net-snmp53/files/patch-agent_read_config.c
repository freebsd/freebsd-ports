--- agent/agent_read_config.c.orig	Mon Jan 24 09:12:58 2005
+++ agent/agent_read_config.c	Mon Jan 24 09:13:13 2005
@@ -84,10 +84,6 @@
 #include <inet/mib2.h>
 #endif
 
-#if HAVE_DMALLOC_H
-#include <dmalloc.h>
-#endif
-
 #if HAVE_UNISTD_H
 #include <unistd.h>
 #endif
