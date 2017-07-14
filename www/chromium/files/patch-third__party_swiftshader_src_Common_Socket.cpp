--- third_party/swiftshader/src/Common/Socket.cpp.orig	2017-06-26 22:11:33.917807000 +0200
+++ third_party/swiftshader/src/Common/Socket.cpp	2017-06-26 22:11:54.516354000 +0200
@@ -20,6 +20,7 @@
 	#include <unistd.h>
 	#include <netdb.h>
 	#include <netinet/in.h>
+       #include <sys/select.h>
 #endif
 
 namespace sw
