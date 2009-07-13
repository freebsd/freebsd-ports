--- ./libssh/kex.c.orig	2009-05-21 18:46:17.000000000 +1000
+++ ./libssh/kex.c	2009-07-09 08:21:13.000000000 +1000
@@ -25,6 +25,10 @@
 #include <stdlib.h>
 #include <stdio.h>
 
+#ifndef _WIN32
+#include <arpa/inet.h>
+#endif
+
 #include "config.h"
 #include "libssh/priv.h"
 #include "libssh/ssh2.h"
