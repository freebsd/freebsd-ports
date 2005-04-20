--- src/file_trans.c.orig	Tue Apr 19 03:52:08 2005
+++ src/file_trans.c	Tue Apr 19 03:00:39 2005
@@ -26,6 +26,7 @@
 #define random rand
 #endif
 
+#include <sys/socket.h>
 #include "debug.h"		// gaim_debug
 #include "ft.h"			// gaim_xfer
 #include "md5.h"
