--- ./libssh/misc.c.orig	2009-05-21 18:46:17.000000000 +1000
+++ ./libssh/misc.c	2009-07-09 08:21:13.000000000 +1000
@@ -37,6 +37,7 @@
 #include <winsock2.h>
 #else
 #include <pwd.h>
+#include <arpa/inet.h>
 #endif
 
 #include "libssh/priv.h"
