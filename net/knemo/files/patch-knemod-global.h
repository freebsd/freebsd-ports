--- src/knemod/global.h.orig	Sat Apr  1 21:44:22 2006
+++ src/knemod/global.h	Sun Apr  2 21:33:36 2006
@@ -22,6 +22,7 @@
 
 #include <qpair.h>
 #include <qcolor.h>
+#include <qdict.h>
 #include <qstring.h>
 
 /**
@@ -36,6 +37,11 @@
     int toolTipContent;
 };
 
+struct AddrData {
+    QString subnetMask;
+    QString broadcastAddress;
+};
+    
 struct InterfaceData
 {
     InterfaceData()
@@ -59,11 +65,9 @@
     unsigned long prevTxBytes;
     unsigned long incomingBytes;
     unsigned long outgoingBytes;
-    QString ipAddress;
-    QString subnetMask;
+    QDict<AddrData> addrData;
     QString hwAddress;
     QString ptpAddress;
-    QString broadcastAddress;
     QString defaultGateway;
     QString rxString;
     QString txString;
