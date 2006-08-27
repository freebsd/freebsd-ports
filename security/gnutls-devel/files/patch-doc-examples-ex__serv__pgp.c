--- doc/examples/ex-serv-pgp.c.orig	Sat Aug 26 20:51:38 2006
+++ doc/examples/ex-serv-pgp.c	Sat Aug 26 20:51:52 2006
@@ -8,6 +8,7 @@
 #include <sys/types.h>
 #include <sys/socket.h>
 #include <arpa/inet.h>
+#include <netinet/in.h>
 #include <string.h>
 #include <unistd.h>
 #include <gnutls/gnutls.h>
