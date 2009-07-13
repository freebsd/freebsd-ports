--- ./libssh/buffer.c.orig	2009-05-21 18:46:17.000000000 +1000
+++ ./libssh/buffer.c	2009-07-09 08:21:13.000000000 +1000
@@ -23,6 +23,11 @@
 
 #include <stdlib.h>
 #include <string.h>
+
+#ifndef _WIN32
+#include <arpa/inet.h>
+#endif
+
 #include "libssh/priv.h"
 
 /** \defgroup ssh_buffer SSH Buffers
