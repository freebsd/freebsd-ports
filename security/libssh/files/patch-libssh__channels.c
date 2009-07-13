--- ./libssh/channels.c.orig	2009-05-21 18:46:17.000000000 +1000
+++ ./libssh/channels.c	2009-07-09 08:21:13.000000000 +1000
@@ -28,6 +28,10 @@
 #include <stdio.h>
 #include <errno.h>
 
+#ifndef _WIN32
+#include <arpa/inet.h>
+#endif
+
 #include "libssh/priv.h"
 #include "libssh/ssh2.h"
 
