--- agent/mibgroup/mibII/at.c.orig	Mon Jan 24 09:08:41 2005
+++ agent/mibgroup/mibII/at.c	Mon Jan 24 09:08:58 2005
@@ -90,9 +90,6 @@
 #if HAVE_WINSOCK_H
 #include <winsock.h>
 #endif
-#if HAVE_DMALLOC_H
-#include <dmalloc.h>
-#endif
 
 #ifdef hpux11
 #include <sys/mib.h>
