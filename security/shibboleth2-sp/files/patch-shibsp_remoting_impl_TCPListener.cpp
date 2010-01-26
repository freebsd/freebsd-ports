
$FreeBSD$

--- shibsp/remoting/impl/TCPListener.cpp.orig
+++ shibsp/remoting/impl/TCPListener.cpp
@@ -38,6 +38,7 @@
 #include <stdio.h>
 #include <stdlib.h>
 #include <errno.h>
+#include <netinet/in.h>
 
 using namespace shibsp;
 using namespace xmltooling;
