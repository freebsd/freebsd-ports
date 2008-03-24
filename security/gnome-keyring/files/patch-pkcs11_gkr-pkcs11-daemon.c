--- pkcs11/gkr-pkcs11-daemon.c.orig	2008-02-11 21:30:48.000000000 -0500
+++ pkcs11/gkr-pkcs11-daemon.c	2008-02-11 21:30:58.000000000 -0500
@@ -35,6 +35,7 @@
 #include <sys/types.h>
 #include <sys/socket.h>
 #include <sys/un.h>
+#include <string.h>
 #include <errno.h>
 #include <unistd.h>
 
