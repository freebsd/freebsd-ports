--- knemod/data.h.orig	Sat Jan 22 00:10:05 2005
+++ knemod/data.h	Fri Jan 21 17:38:50 2005
@@ -22,6 +22,7 @@
 
 #include <qpair.h>
 #include <qcolor.h>
+#include <qdict.h>
 #include <qstring.h>
 #include <qvaluevector.h>
 
@@ -41,6 +42,11 @@
     int toolTipContent;
 };
 
+struct AddrData {
+    QString subnetMask;
+    QString broadcastAddress;
+};
+    
 struct InterfaceData
 {
     InterfaceData::InterfaceData()
@@ -64,11 +70,9 @@
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
