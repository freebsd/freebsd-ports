--- third-party/libutp/utp.cpp.orig	2011-04-29 21:45:38.000000000 -0500
+++ third-party/libutp/utp.cpp	2011-04-29 21:47:05.000000000 -0500
@@ -10,6 +10,9 @@
 #include <stdlib.h>
 #include <errno.h>
 #include <limits.h> // for UINT_MAX
+#include <sys/types.h>
+#include <sys/socket.h>
+#include <netinet/in.h>
 
 #ifdef WIN32
 #include "win32_inet_ntop.h"
