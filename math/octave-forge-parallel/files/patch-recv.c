--- recv.cc.orig	2013-11-16 22:29:55.000000000 +0100
+++ recv.cc	2013-11-16 22:30:24.000000000 +0100
@@ -22,9 +22,11 @@
 #include <octave/oct-stream.h>
 #include <octave/oct-map.h>
 
+#include <sys/types.h>
 #include <sys/socket.h>
 #include <sys/poll.h>
 #include <netinet/in.h>
+#include <unistd.h>
 #include <netdb.h>
 
 
