--- nepenthes-core/src/TCPSocket.cpp.orig
+++ nepenthes-core/src/TCPSocket.cpp
@@ -29,6 +29,7 @@
 
 #include "config.h"
 
+#include <cstring>
 #include <sys/types.h>
 
 #ifdef WIN32
