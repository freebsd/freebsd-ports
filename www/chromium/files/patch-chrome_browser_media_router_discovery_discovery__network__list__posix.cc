--- chrome/browser/media/router/discovery/discovery_network_list_posix.cc.orig	2022-02-07 13:39:41 UTC
+++ chrome/browser/media/router/discovery/discovery_network_list_posix.cc
@@ -5,11 +5,12 @@
 #include "chrome/browser/media/router/discovery/discovery_network_list.h"
 
 #include <ifaddrs.h>
+#include <sys/socket.h>
+#include <sys/types.h>
+#include <sys/time.h>
 #include <net/if.h>
 #include <net/if_arp.h>
 #include <netinet/in.h>
-#include <sys/socket.h>
-#include <sys/types.h>
 
 #include <algorithm>
 
@@ -18,7 +19,7 @@
 #include "chrome/browser/media/router/discovery/discovery_network_list_wifi.h"
 #include "net/base/net_errors.h"
 
-#if !defined(OS_MAC)
+#if !defined(OS_MAC) && !defined(OS_BSD)
 #include <netpacket/packet.h>
 #else
 #include <net/if_dl.h>
@@ -27,7 +28,7 @@
 namespace media_router {
 namespace {
 
-#if !defined(OS_MAC)
+#if !defined(OS_MAC) && !defined(OS_BSD)
 using sll = struct sockaddr_ll;
 #define SOCKET_ARP_TYPE(s) ((s)->sll_hatype)
 #define SOCKET_ADDRESS_LEN(s) ((s)->sll_halen)
