--- src/acct.c.orig	Tue Jun 12 07:31:23 2001
+++ src/acct.c	Tue Jun 26 17:00:10 2001
@@ -84,7 +84,7 @@
 	struct stat	backup;
 	SQLREC backuprecord = {"", "", "",  "", 0, "", "", 0, "", 0, "", "", 0, 0, "", "", "", "", "", "", 0};
 #endif
-	SQLREC sqlrecord = {"", "", "", "", 0, "", "", 0, "", 0, "", "", 0, 0, "", "", "", "", "", "", 0};
+ 	SQLREC sqlrecord =    {"", "", "", "", 0, 0, 0, "", 0, 0, 0, 0, 0, 0, 0, "",  0, 0, "", "", 0};
 	VALUE_PAIR	*pair;
 	int		ret = 0;
 
@@ -111,18 +111,11 @@
                 	break;
 
                 case PW_NAS_PORT_TYPE:
-			valbuf = (char *)dict_valgetname(pair->lvalue, pair->name);
-			if(valbuf != (char *)NULL) {
-               			strncpy(sqlrecord.NASPortType, valbuf, SQLBIGREC);
-			}
+               		sqlrecord.NASPortType = pair->lvalue;
 			break;
 
                 case PW_ACCT_STATUS_TYPE:
        			sqlrecord.AcctStatusTypeId = pair->lvalue;
-			valbuf = (char *)dict_valgetname(pair->lvalue, pair->name);
-			if(valbuf != (char *)NULL) {
-                		strncpy(sqlrecord.AcctStatusType, valbuf, SQLBIGREC);
-			}
 			break;
 
                 case PW_ACCT_SESSION_TIME:
@@ -130,16 +123,9 @@
                 	break;
 
                 case PW_ACCT_AUTHENTIC:
-			valbuf = (char *)dict_valgetname(pair->lvalue, pair->name);
-			if(valbuf != (char *)NULL) {
-                		strncpy(sqlrecord.AcctAuthentic, valbuf, SQLBIGREC);
-			}
+            		sqlrecord.AcctAuthentic = pair->lvalue;
 			break;
 
-                case PW_CONNECT_INFO:
-                	strncpy(sqlrecord.ConnectInfo, pair->strvalue, SQLBIGREC);
-                	break;
-
                 case PW_ACCT_INPUT_OCTETS:
                 	sqlrecord.AcctInputOctets = pair->lvalue;
                 	break;
@@ -148,33 +134,32 @@
                 	sqlrecord.AcctOutputOctets = pair->lvalue;
                 	break;
 
-                case PW_CALLED_STATION_ID:
-                	strncpy(sqlrecord.CalledStationId, pair->strvalue, SQLLILREC);
-                	break;
+                case PW_CISCO_DISCONNECT_CAUSE:
+                	sqlrecord.CiscoDisconnectCause = pair->lvalue;
+			break;
 
-                case PW_CALLING_STATION_ID:
-                	strncpy(sqlrecord.CallingStationId, pair->strvalue, SQLLILREC);
-                	break;
+                case PW_CISCO_DATA_RATE:
+                	sqlrecord.CiscoDataRate = pair->lvalue;
+			break;
 
-                case PW_ACCT_TERMINATE_CAUSE:
-			valbuf = (char *)dict_valgetname(pair->lvalue, pair->name);
-			if(valbuf != (char *)NULL) {
-                		strncpy(sqlrecord.AcctTerminateCause, valbuf, SQLBIGREC);
-			}
+                case PW_CISCO_XMIT_RATE:
+                	sqlrecord.CiscoXmitRate = pair->lvalue;
 			break;
 
+                case PW_CALLED_STATION_ID:
+                	strncpy(sqlrecord.CalledStationID, pair->strvalue, SQLBIGREC);
+                	break;
+                	
+                case PW_CALLING_STATION_ID:
+                	strncpy(sqlrecord.CallingStationID, pair->strvalue, SQLBIGREC);
+                	break;
+                	
                 case PW_SERVICE_TYPE:
-			valbuf = (char *)dict_valgetname(pair->lvalue, pair->name);
-			if(valbuf != (char *)NULL) {
-                		strncpy(sqlrecord.ServiceType, valbuf, SQLBIGREC);
-			}
+                	sqlrecord.ServiceType = pair->lvalue;
 			break;
 
                 case PW_FRAMED_PROTOCOL:
-			valbuf = (char *)dict_valgetname(pair->lvalue, pair->name);
-			if(valbuf != (char *)NULL) {
-                		strncpy(sqlrecord.FramedProtocol, valbuf, SQLBIGREC);
-			}
+              		sqlrecord.FramedProtocol = pair->lvalue;
 			break;
 
                 case PW_FRAMED_IP_ADDRESS:
