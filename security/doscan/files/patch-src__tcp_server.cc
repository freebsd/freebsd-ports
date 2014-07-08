--- ./src/tcp_server.cc.orig	2014-07-08 13:38:28.586070857 +0200
+++ ./src/tcp_server.cc	2014-07-08 13:38:54.175974881 +0200
@@ -22,6 +22,7 @@
 
 #include <cerrno>
 #include <cstdio>
+#include <cstdlib>
 #include <fcntl.h>
 #include <netinet/in.h>
 #include <sys/fcntl.h>
