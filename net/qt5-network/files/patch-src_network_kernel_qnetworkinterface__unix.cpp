Clean up interface type and MTU detection.

 - Introduce a class SockPuppet that handles closing the socket
   automatically, and handles different address families as well.
 - Finding MTU requires using AF_LOCAL, cribbed that detail from ifconfig.c
 - Zero out structures more diligently, initialize pointers to nullptr.
 - In particular, don't use a union of structs passed in to ioctl().
   Make them separate structs (with block scope so the compiler might
   place them on top of each other, that would be ok).
 - IFM_FDDI (still) exists in 11.2, not in 12.0

--- src/network/kernel/qnetworkinterface_unix.cpp.orig	2019-10-25 07:16:48 UTC
+++ src/network/kernel/qnetworkinterface_unix.cpp
@@ -420,13 +420,24 @@ QT_BEGIN_INCLUDE_NAMESPACE
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
+};
+
 static QNetworkInterface::InterfaceType probeIfType(int socket, int iftype, struct ifmediareq *req)
 {
     // Determine the interface type.
@@ -480,16 +491,9 @@ static QNetworkInterface::InterfaceType probeIfType(in
 static QList<QNetworkInterfacePrivate *> createInterfaces(ifaddrs *rawList)
 {
     QList<QNetworkInterfacePrivate *> interfaces;
-    union {
-        struct ifmediareq mediareq;
-        struct ifreq req;
-    };
-    int socket = -1;
-    memset(&mediareq, 0, sizeof(mediareq));
 
-    // ensure both structs start with the name field, of size IFNAMESIZ
-    Q_STATIC_ASSERT(sizeof(mediareq.ifm_name) == sizeof(req.ifr_name));
-    Q_ASSERT(&mediareq.ifm_name == &req.ifr_name);
+    SockPuppet<AF_INET> socket;
+    SockPuppet<AF_LOCAL> localSocket;
 
     // on NetBSD we use AF_LINK and sockaddr_dl
     // scan the list for that family
@@ -503,14 +507,22 @@ static QList<QNetworkInterfacePrivate *> createInterfa
             iface->name = QString::fromLatin1(ptr->ifa_name);
             iface->flags = convertFlags(ptr->ifa_flags);
             iface->hardwareAddress = iface->makeHwAddress(sdl->sdl_alen, (uchar*)LLADDR(sdl));
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
 
-            qstrncpy(mediareq.ifm_name, ptr->ifa_name, sizeof(mediareq.ifm_name));
-            iface->type = probeIfType(openSocket(socket), sdl->sdl_type, &mediareq);
-            iface->mtu = getMtu(socket, &req);
         }
 
-    if (socket != -1)
-        qt_safe_close(socket);
     return interfaces;
 }
 
@@ -609,7 +621,7 @@ static QList<QNetworkInterfacePrivate *> interfaceList
 {
     QList<QNetworkInterfacePrivate *> interfaces;
 
-    ifaddrs *interfaceListing;
+    ifaddrs *interfaceListing = nullptr;
     if (getifaddrs(&interfaceListing) == -1) {
         // error
         return interfaces;
