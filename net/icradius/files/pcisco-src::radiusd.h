--- src/radiusd.h.old	Tue Sep  5 05:50:25 2000
+++ src/radiusd.h	Thu Jan 25 14:53:27 2001
@@ -142,21 +142,21 @@
         char                            Realm[SQLBIGREC];
         char                            NASIPAddress[SQLLILREC];
         unsigned long                   NASPortId;
-        char                            NASPortType[SQLBIGREC];
-        char                            AcctStatusType[SQLBIGREC];
+        unsigned long                   NASPortType;
         unsigned int                    AcctStatusTypeId;
         char                            AcctTimeStamp[20];
         unsigned long                   AcctSessionTime;
-        char                            AcctAuthentic[SQLBIGREC];
-        char                            ConnectInfo[SQLBIGREC];
+        unsigned long                   AcctAuthentic;
         unsigned long                   AcctInputOctets;
         unsigned long                   AcctOutputOctets;
-        char                            CalledStationId[SQLLILREC];
-        char                            CallingStationId[SQLLILREC];
-        char                            AcctTerminateCause[SQLBIGREC];
-        char                            ServiceType[SQLBIGREC];
-        char                            FramedProtocol[SQLBIGREC];
+        unsigned long                   CiscoDisconnectCause;
+        unsigned long                   ServiceType;
+        unsigned long                   FramedProtocol;
         char                            FramedIPAddress[SQLLILREC];
+        unsigned long			CiscoDataRate;
+        unsigned long			CiscoXmitRate;
+        char				CallingStationID[SQLBIGREC];
+        char				CalledStationID[SQLBIGREC];
         unsigned long                   AcctDelayTime;
 } SQLREC; 
 
