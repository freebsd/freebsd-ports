--- shibsp/remoting/impl/TCPListener.cpp.orig	2018-07-10 01:17:23 UTC
+++ shibsp/remoting/impl/TCPListener.cpp
@@ -55,6 +55,7 @@
 #include <stdlib.h>
 #include <fcntl.h>
 #include <errno.h>
+#include <netinet/in.h>
 
 using namespace shibsp;
 using namespace xmltooling;
