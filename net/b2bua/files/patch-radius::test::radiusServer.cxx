
$FreeBSD$

--- radius/test/radiusServer.cxx	2003/01/18 20:14:02	1.1
+++ radius/test/radiusServer.cxx	2003/01/18 20:14:31
@@ -52,6 +52,8 @@
 
 #include <cstdio>
 
+#include <netinet/in.h>
+
 #include "cpLog.h"
 #include "UdpStack.hxx"
 #include "TimeFunc.hxx"
