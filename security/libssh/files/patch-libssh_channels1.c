--- libssh/channels1.c.orig	2010-03-19 22:34:30.000000000 +0800
+++ libssh/channels1.c	2010-03-19 22:35:51.000000000 +0800
@@ -26,6 +26,9 @@
 #include <stdlib.h>
 #include <unistd.h>
 #include <stdio.h>
+#ifndef _WIN32
+#include <arpa/inet.h>
+#endif
 #include "libssh/priv.h"
 #include "libssh/ssh1.h"
 #include "libssh/buffer.h"
