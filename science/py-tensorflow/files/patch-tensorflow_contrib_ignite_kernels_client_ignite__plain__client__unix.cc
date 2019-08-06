--- tensorflow/contrib/ignite/kernels/client/ignite_plain_client_unix.cc.orig	2019-07-07 13:40:21.593527000 +0100
+++ tensorflow/contrib/ignite/kernels/client/ignite_plain_client_unix.cc	2019-07-07 13:40:59.586340000 +0100
@@ -20,6 +20,10 @@
 #include <sys/socket.h>
 #include <unistd.h>
 
+#ifdef __FreeBSD__
+#include <netinet/in.h>
+#endif
+
 #include <iostream>
 #include <map>
 
