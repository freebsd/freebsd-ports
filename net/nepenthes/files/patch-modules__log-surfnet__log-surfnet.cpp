--- modules/log-surfnet/log-surfnet.cpp.orig
+++ modules/log-surfnet/log-surfnet.cpp
@@ -27,6 +27,7 @@
 
 /* $Id: log-surfnet.cpp 932 2007-02-21 14:16:50Z common $ */
 
+#include <cstdlib>
 #include <sstream>
 #include <sys/types.h>
 #include <sys/socket.h>
