--- ./libssh/client.c.orig	2009-05-21 18:46:18.000000000 +1000
+++ ./libssh/client.c	2009-07-09 08:21:13.000000000 +1000
@@ -24,6 +24,11 @@
 #include <stdio.h>
 #include <stdlib.h>
 #include <string.h>
+
+#ifndef _WIN32
+#include <arpa/inet.h>
+#endif
+
 #include "libssh/priv.h"
 #include "libssh/ssh2.h"
 
