--- connect.cc.orig	2013-11-16 22:26:59.000000000 +0100
+++ connect.cc	2013-11-16 22:27:54.000000000 +0100
@@ -25,7 +25,9 @@
 #include <octave/oct.h>
 #include <oct-env.h>
 
+#include <sys/types.h>
 #include <sys/socket.h>
+#include <unistd.h>
 #include <errno.h>
 #include <netdb.h>
 #include <netinet/in.h> // reported necessary for FreeBSD-8
