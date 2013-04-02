--- libpbe/src/ip.cc.orig	2008-12-18 21:18:43.000000000 +0100
+++ libpbe/src/ip.cc	2013-03-30 17:48:22.000000000 +0100
@@ -23,6 +23,7 @@
 #include <sys/un.h>
 #include <netdb.h>
 #include <unistd.h>
+#include <string.h>
 
 using namespace std;
 
