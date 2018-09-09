--- src/network/kernel/qnetworkinterface_unix.cpp.orig	2018-06-15 07:29:31 UTC
+++ src/network/kernel/qnetworkinterface_unix.cpp
@@ -463,9 +463,6 @@ static QNetworkInterface::InterfaceType probeIfType(in
         case IFM_ETHER:
             return QNetworkInterface::Ethernet;
 
-        case IFM_FDDI:
-            return QNetworkInterface::Fddi;
-
         case IFM_IEEE80211:
             return QNetworkInterface::Ieee80211;
         }
