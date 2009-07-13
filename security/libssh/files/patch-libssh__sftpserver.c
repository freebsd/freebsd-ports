--- ./libssh/sftpserver.c.orig	2009-05-21 18:46:17.000000000 +1000
+++ ./libssh/sftpserver.c	2009-07-09 08:21:13.000000000 +1000
@@ -26,6 +26,10 @@
 #include <string.h>
 #include <stdio.h>
 
+#ifndef _WIN32
+#include <arpa/inet.h>
+#endif
+
 #include "libssh/libssh.h"
 #include "libssh/sftp.h"
 #include "libssh/ssh2.h"
