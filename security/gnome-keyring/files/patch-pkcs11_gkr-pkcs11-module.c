--- pkcs11/gkr-pkcs11-module.c.orig	2008-02-11 21:26:56.000000000 -0500
+++ pkcs11/gkr-pkcs11-module.c	2008-02-11 21:27:08.000000000 -0500
@@ -36,6 +36,7 @@
 #include <sys/socket.h>
 #include <sys/un.h>
 
+#include <string.h>
 #include <stdlib.h>
 #include <stdint.h>
 #include <pthread.h>
