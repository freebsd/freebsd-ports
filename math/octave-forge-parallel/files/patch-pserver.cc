--- pserver.cc.orig	2013-11-16 22:30:37.000000000 +0100
+++ pserver.cc	2013-11-16 22:31:47.000000000 +0100
@@ -27,6 +27,7 @@
 #include <cmd-edit.h>
 #include <toplev.h>
 
+#include <sys/types.h>
 #include <sys/socket.h>
 #include <iostream>
 #include <sys/stat.h>
@@ -34,6 +35,8 @@
 #include <errno.h>
 #include <netdb.h>
 #include <netinet/in.h> // reported necessary for FreeBSD-8
+#include <unistd.h>
+#include <stdlib.h>
 
 #include "sock-stream.h"
 
