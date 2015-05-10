--- osquery/tables/networking/interfaces.cpp.orig	2015-05-08 22:48:42 UTC
+++ osquery/tables/networking/interfaces.cpp
@@ -11,8 +11,8 @@
 #include <sstream>
 #include <iomanip>
 
-#include <ifaddrs.h>
 #include <net/if.h>
+#include <ifaddrs.h>
 #include <sys/socket.h>
 
 #ifdef __linux__
