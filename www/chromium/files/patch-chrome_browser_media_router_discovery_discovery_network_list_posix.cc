--- chrome/browser/media/router/discovery/discovery_network_list_posix.cc.orig	2017-09-10 01:42:30.124986000 +0200
+++ chrome/browser/media/router/discovery/discovery_network_list_posix.cc	2017-09-10 01:44:26.941752000 +0200
@@ -10,6 +10,7 @@
 #include <netinet/in.h>
 #include <sys/socket.h>
 #include <sys/types.h>
+#include <sys/time.h>
 
 #include <algorithm>
 
@@ -19,7 +20,7 @@
 #include "chrome/browser/media/router/discovery/discovery_network_list_wifi.h"
 #include "net/base/net_errors.h"
 
-#if !defined(OS_MACOSX)
+#if !defined(OS_MACOSX) && !defined(OS_BSD)
 #include <netpacket/packet.h>
 #else
 #include <net/if_dl.h>
@@ -27,7 +28,7 @@
 
 namespace {
 
-#if !defined(OS_MACOSX)
+#if !defined(OS_MACOSX) && !defined(OS_BSD)
 using sll = struct sockaddr_ll;
 #define SOCKET_ARP_TYPE(s) ((s)->sll_hatype)
 #define SOCKET_ADDRESS_LEN(s) ((s)->sll_halen)
