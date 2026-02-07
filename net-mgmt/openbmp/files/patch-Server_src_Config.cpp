--- Server/src/Config.cpp.orig	2017-09-14 09:34:05 UTC
+++ Server/src/Config.cpp
@@ -15,6 +15,7 @@
 #include <unistd.h>
 
 #include <arpa/inet.h>
+#include <sys/socket.h>
 #include <yaml-cpp/yaml.h>
 #include <boost/xpressive/xpressive.hpp>
 #include <boost/exception/all.hpp>
