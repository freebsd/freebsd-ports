--- xbmc/platform/posix/filesystem/SMBWSDiscoveryListener.cpp.orig	2022-05-22 10:20:23 UTC
+++ xbmc/platform/posix/filesystem/SMBWSDiscoveryListener.cpp
@@ -27,6 +27,7 @@
 #include <arpa/inet.h>
 #include <fmt/format.h>
 #include <sys/select.h>
+#include <sys/socket.h>
 #include <unistd.h>
 
 using namespace WSDiscovery;
