
$FreeBSD$

--- radius/test/radiusClient.cxx	2003/01/18 20:10:53	1.1
+++ radius/test/radiusClient.cxx	2003/01/18 20:11:19
@@ -52,6 +52,8 @@
 
 #include <cstdio>
 
+#include <netinet/in.h>
+
 #include "cpLog.h"
 #include "UdpStack.hxx"
 #include "TimeFunc.hxx"
