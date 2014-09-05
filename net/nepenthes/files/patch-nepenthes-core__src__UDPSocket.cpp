--- nepenthes-core/src/UDPSocket.cpp.orig
+++ nepenthes-core/src/UDPSocket.cpp
@@ -27,7 +27,8 @@
 
 /* $Id: UDPSocket.cpp 1410 2007-10-12 13:07:23Z common $ */
 
-#include <errno.h>
+#include <cstring>
+#include <cerrno>
 #include <sys/types.h>
 
 #ifdef WIN32
