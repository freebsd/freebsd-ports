--- ./libssh/sftp.c.orig	2009-05-21 18:46:17.000000000 +1000
+++ ./libssh/sftp.c	2009-07-09 08:21:13.000000000 +1000
@@ -31,6 +31,10 @@
 #include <sys/types.h>
 #include <sys/stat.h>
 
+#ifndef _WIN32
+#include <arpa/inet.h>
+#endif
+
 #include "libssh/priv.h"
 #include "libssh/ssh2.h"
 #include "libssh/sftp.h"
