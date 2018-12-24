Determine suitable bearer. This code is basically the same
as the Linux code, except out ioctl()s are named differently
and we need an AF_LOCAL socket (this detail cribbed from ifconfig.c).
If getting the HW address succeeds, assume it's Ethernet. Tested
with two Ethernet cards and a vlan (all of which have a MAC reported
by ifconfig).

--- src/plugins/bearer/generic/qgenericengine.cpp.orig	2018-12-03 12:15:26.000000000 +0100
+++ src/plugins/bearer/generic/qgenericengine.cpp	2018-12-23 12:42:48.095145000 +0100
@@ -82,7 +82,7 @@
 // needed as interface is used as parameter name in qGetInterfaceType
 #undef interface
 
-#ifdef Q_OS_LINUX
+#if defined(Q_OS_LINUX) || defined(Q_OS_FREEBSD)
 #include <sys/socket.h>
 #include <sys/ioctl.h>
 #include <net/if.h>
@@ -139,6 +139,23 @@
 
     if (result >= 0 && request.ifr_hwaddr.sa_family == ARPHRD_ETHER)
         return QNetworkConfiguration::BearerEthernet;
+
+#elif defined(Q_OS_FREEBSD)
+    int sock = socket(AF_LOCAL, SOCK_DGRAM, 0);
+
+    ifreq request;
+    memset(&request, 0, sizeof(struct ifreq));
+    strncpy(request.ifr_name, interface.toLocal8Bit().data(), sizeof(request.ifr_name) - 1);
+    request.ifr_name[sizeof(request.ifr_name) - 1] = '\0';
+
+    if (sock >= 0) {
+        int result = ioctl(sock, SIOCGHWADDR, &request);
+        close(sock);
+
+        if (result >= 0)
+            return QNetworkConfiguration::BearerEthernet;
+    }
+
 #elif defined(Q_OS_WINRT)
     ComPtr<INetworkInformationStatics> networkInfoStatics;
     HRESULT hr = GetActivationFactory(HString::MakeReference(RuntimeClass_Windows_Networking_Connectivity_NetworkInformation).Get(), &networkInfoStatics);
