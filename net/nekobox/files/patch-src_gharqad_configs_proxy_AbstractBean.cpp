-- Add missing network headers for FreeBSD.
--
-- This patch includes <sys/types.h> and <sys/socket.h> which are required
-- for networking constants and structures on FreeBSD.
--- src/gharqad/configs/proxy/AbstractBean.cpp.orig	2026-06-04 04:04:10 UTC
+++ src/gharqad/configs/proxy/AbstractBean.cpp
@@ -3,6 +3,9 @@
 #include <winsock2.h>
 #include <ws2tcpip.h>
 #else
+#include <sys/types.h>
+#include <sys/socket.h>
+#include <netinet/in.h>
 #include <netdb.h>
 #include <arpa/inet.h>
 #endif
