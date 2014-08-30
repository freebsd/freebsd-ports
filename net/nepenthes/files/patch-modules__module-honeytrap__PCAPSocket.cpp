--- modules/module-honeytrap/PCAPSocket.cpp.orig
+++ modules/module-honeytrap/PCAPSocket.cpp
@@ -28,12 +28,14 @@
 /* $Id: PCAPSocket.cpp 697 2006-11-11 09:17:19Z common $ */
 
 #include <unistd.h>
-#include <time.h>
+#include <cstdlib>
+#include <cstring>
+#include <ctime>
 #include <sys/types.h>
 #include <sys/socket.h>
 #include <netinet/in.h>
 #include <arpa/inet.h>
-#include <errno.h>
+#include <cerrno>
 
 #include "LogManager.hpp"
 #include "PCAPSocket.hpp"
