daemon/ssdpwatcher.cpp:122:17: error: invalid suffix on literal; C++11 
requires a space between literal and identifier [-Wreserved-user-defined-literal]

--- daemon/ssdpwatcher.cpp.orig	2018-01-06 18:31:07 UTC
+++ daemon/ssdpwatcher.cpp
@@ -119,8 +119,8 @@ qDebug() << "Trying to find UPnP devices on the local 
     // send a HTTP M-SEARCH message to 239.255.255.250:1900
     const QByteArray searchMessage =
         "M-SEARCH * HTTP/1.1\r\n"
-        "HOST: "SSDP_BROADCAST_ADDRESS":"SSDP_PORT"\r\n"
-        "ST:"ROOTDEVICE"\r\n"
+        "HOST: " SSDP_BROADCAST_ADDRESS ":" SSDP_PORT "\r\n"
+        "ST:" ROOTDEVICE "\r\n"
 //         "ST: ssdp:all\r\n"
         "MAN:\"ssdp:discover\"\r\n"
         "MX:" + QByteArray::number(searchTimeout) + "\r\n" // max number of seconds to wait for response
