--- ./src/half_duplex.cc.orig	2014-07-08 13:35:10.175988570 +0200
+++ ./src/half_duplex.cc	2014-07-08 13:35:42.546019678 +0200
@@ -22,6 +22,7 @@
 
 #include <cerrno>
 #include <cstdio>
+#include <cstdlib>
 #include <fcntl.h>
 #include <string>
 #include <sys/fcntl.h>
