--- ./libssh/string.c.orig	2009-05-21 18:46:17.000000000 +1000
+++ ./libssh/string.c	2009-07-09 08:21:13.000000000 +1000
@@ -24,6 +24,11 @@
 #include <stdlib.h>
 #include <unistd.h>
 #include <string.h>
+
+#ifndef _WIN32
+#include <arpa/inet.h>
+#endif
+
 #include "libssh/priv.h"
 
 /** \defgroup ssh_string SSH Strings
