--- send.cc.orig	2013-11-16 22:35:29.000000000 +0100
+++ send.cc	2013-11-16 22:35:56.000000000 +0100
@@ -21,10 +21,12 @@
 #include <octave/ls-oct-binary.h>
 #include <octave/oct-stream.h>
 
+#include <sys/types.h>
 #include <sys/socket.h>
 #include <sys/poll.h>
 #include <netinet/in.h>
 #include <netdb.h>
+#include <unistd.h>
 
 
 DEFUN_DLD (send, args, , "send (X, sockets)\n\
