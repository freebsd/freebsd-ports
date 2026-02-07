Determine suitable bearer. This code is basically the same
as the Linux code, except out ioctl()s are named differently
and we need an AF_LOCAL socket (this detail cribbed from ifconfig.c).
If getting the HW address succeeds, assume it's Ethernet. Tested
with two Ethernet cards and a vlan (all of which have a MAC reported
by ifconfig).

--- src/plugins/bearer/generic/qgenericengine.cpp.orig	2018-12-03 11:15:26 UTC
+++ src/plugins/bearer/generic/qgenericengine.cpp
@@ -82,7 +82,7 @@ using namespace ABI::Windows::Networking::Connectivity
 // needed as interface is used as parameter name in qGetInterfaceType
 #undef interface
 
-#ifdef Q_OS_LINUX
+#if defined(Q_OS_LINUX) || defined(Q_OS_FREEBSD)
 #include <sys/socket.h>
 #include <sys/ioctl.h>
 #include <net/if.h>
@@ -139,6 +139,23 @@ static QNetworkConfiguration::BearerType qGetInterface
 
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
@@ -231,9 +248,11 @@ static QNetworkConfiguration::BearerType qGetInterface
 QGenericEngine::QGenericEngine(QObject *parent)
 :   QBearerEngineImpl(parent)
 {
+#ifndef QT_NO_NETWORKINTERFACE
     //workaround for deadlock in __cxa_guard_acquire with webkit on macos x
     //initialise the Q_GLOBAL_STATIC in same thread as the AtomicallyInitializedStatic
     (void)QNetworkInterface::interfaceFromIndex(0);
+#endif
 }
 
 QGenericEngine::~QGenericEngine()
