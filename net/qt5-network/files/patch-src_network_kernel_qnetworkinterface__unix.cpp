Clean up interface type and MTU detection.

 - Introduce a class SockPuppet that handles closing the socket
   automatically, and handles different address families as well.
 - Finding MTU requires using AF_LOCAL, cribbed that detail from ifconfig.c
 - Zero out structures more diligently, initialize pointers to nullptr.
 - In particular, don't use a union of structs passed in to ioctl().
   Make them separate structs (with block scope so the compiler might
   place them on top of each other, that would be ok).
 - IFM_FDDI (still) exists in 11.2, not in 12.0

--- src/network/kernel/qnetworkinterface_unix.cpp.orig	2018-12-03 11:15:26 UTC
+++ src/network/kernel/qnetworkinterface_unix.cpp
@@ -419,12 +419,23 @@ QT_BEGIN_INCLUDE_NAMESPACE
 #endif // QT_PLATFORM_UIKIT
 QT_END_INCLUDE_NAMESPACE
 
-static int openSocket(int &socket)
+template<int address_family> struct SockPuppet
 {
-    if (socket == -1)
-        socket = qt_safe_socket(AF_INET, SOCK_DGRAM, 0);
-    return socket;
-}
+    int socket{-1};
+
+    int open() 
+    {
+        if (socket == -1)
+            socket = qt_safe_socket(address_family, SOCK_DGRAM, 0);
+        return socket;
+    }
+
+    ~SockPuppet()
+    {
+        if (socket != -1)
+            qt_safe_close(socket);
+    }
+} ;
 
 static QNetworkInterface::InterfaceType probeIfType(int socket, int iftype, struct ifmediareq *req)
 {
@@ -463,9 +474,6 @@ static QNetworkInterface::InterfaceType 
         case IFM_ETHER:
             return QNetworkInterface::Ethernet;
 
-        case IFM_FDDI:
-            return QNetworkInterface::Fddi;
-
         case IFM_IEEE80211:
             return QNetworkInterface::Ieee80211;
         }
@@ -477,15 +485,8 @@ static QNetworkInterface::InterfaceType 
 static QList<QNetworkInterfacePrivate *> createInterfaces(ifaddrs *rawList)
 {
     QList<QNetworkInterfacePrivate *> interfaces;
-    union {
-        struct ifmediareq mediareq;
-        struct ifreq req;
-    };
-    int socket = -1;
-
-    // ensure both structs start with the name field, of size IFNAMESIZ
-    Q_STATIC_ASSERT(sizeof(mediareq.ifm_name) == sizeof(req.ifr_name));
-    Q_ASSERT(&mediareq.ifm_name == &req.ifr_name);
+    SockPuppet<AF_INET> socket;
+    SockPuppet<AF_LOCAL> localSocket;
 
     // on NetBSD we use AF_LINK and sockaddr_dl
     // scan the list for that family
@@ -500,13 +501,21 @@ static QList<QNetworkInterfacePrivate *>
             iface->flags = convertFlags(ptr->ifa_flags);
             iface->hardwareAddress = iface->makeHwAddress(sdl->sdl_alen, (uchar*)LLADDR(sdl));
 
-            strlcpy(mediareq.ifm_name, ptr->ifa_name, sizeof(mediareq.ifm_name));
-            iface->type = probeIfType(openSocket(socket), sdl->sdl_type, &mediareq);
-            iface->mtu = getMtu(socket, &req);
+            {
+                ifmediareq req;
+                memset(&req, 0, sizeof(req));
+                strncpy(req.ifm_name, ptr->ifa_name, sizeof(req.ifm_name));
+                iface->type = probeIfType(socket.open(), sdl->sdl_type, &req);
+            }
+            {
+                ifreq req;
+                memset(&req, 0, sizeof(req));
+                strncpy(req.ifr_name, ptr->ifa_name, sizeof(req.ifr_name));
+                req.ifr_addr.sa_family = AF_LOCAL;
+                iface->mtu = getMtu(localSocket.open(), &req);
+            }
         }
 
-    if (socket != -1)
-        qt_safe_close(socket);
     return interfaces;
 }
 
@@ -605,7 +614,7 @@ static QList<QNetworkInterfacePrivate *>
 {
     QList<QNetworkInterfacePrivate *> interfaces;
 
-    ifaddrs *interfaceListing;
+    ifaddrs *interfaceListing = nullptr;
     if (getifaddrs(&interfaceListing) == -1) {
         // error
         return interfaces;
