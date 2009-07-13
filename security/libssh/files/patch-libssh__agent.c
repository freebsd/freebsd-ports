--- ./libssh/agent.c.orig	2009-05-21 18:46:17.000000000 +1000
+++ ./libssh/agent.c	2009-07-09 08:21:13.000000000 +1000
@@ -44,6 +44,10 @@
 #include <poll.h>
 #include <unistd.h>
 
+#ifndef _WIN32
+#include <arpa/inet.h>
+#endif
+
 #include "libssh/agent.h"
 #include "libssh/priv.h"
 
