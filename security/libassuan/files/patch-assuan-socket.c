--- src/assuan-socket.c.orig	Thu Nov 25 19:38:50 2004
+++ src/assuan-socket.c	Thu Nov 25 19:39:09 2004
@@ -23,6 +23,7 @@
 #include <windows.h>
 #include <io.h>
 #else
+#include <sys/types.h>
 #include <sys/socket.h>
 #endif
 #include "assuan-defs.h"
