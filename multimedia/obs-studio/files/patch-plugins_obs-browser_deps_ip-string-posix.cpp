--- plugins/obs-browser/deps/ip-string-posix.cpp.orig	2026-08-14 22:07:07 UTC
+++ plugins/obs-browser/deps/ip-string-posix.cpp
@@ -17,6 +17,8 @@
 
 #include "ip-string.hpp"
 
+#include <sys/socket.h>
+#include <netinet/in.h>
 #include <arpa/inet.h>
 #include <stdio.h>
 
