--- ./libssh/messages.c.orig	2009-05-21 18:46:17.000000000 +1000
+++ ./libssh/messages.c	2009-07-09 08:21:13.000000000 +1000
@@ -34,6 +34,11 @@
 
 #include <string.h>
 #include <stdlib.h>
+
+#ifndef _WIN32
+#include <arpa/inet.h>
+#endif
+
 #include "libssh/libssh.h"
 #include "libssh/priv.h"
 #include "libssh/server.h"
