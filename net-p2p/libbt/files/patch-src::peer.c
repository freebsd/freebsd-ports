--- src/peer.c.old	Thu Feb 26 17:34:55 2004
+++ src/peer.c	Thu Feb 26 17:35:21 2004
@@ -1,5 +1,6 @@
 #include "config.h"
 
+#include <sys/types.h>
 #if WIN32
 //	#include <winsock2.h>
 #else
@@ -13,7 +14,6 @@
 	#include <fcntl.h>
     #endif
 #endif
-#include <sys/types.h>
 #include <string.h>
 #include <errno.h>
 #include <time.h>
