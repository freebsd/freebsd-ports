--- src/mysql.c.old	Sat Oct 21 23:28:04 2000
+++ src/mysql.c	Thu Jan 25 14:51:54 2001
@@ -471,7 +475,15 @@
 		/* The Terminal server informed us that it was rebooted
 		 * STOP all records from this NAS */
 
-		sprintf(querystr, "UPDATE %s SET AcctStopTime='%s', AcctSessionTime=unix_timestamp('%s') - unix_timestamp(AcctStartTime), AcctTerminateCause='%s', AcctStopDelay = %ld WHERE AcctSessionTime=0 AND AcctStopTime=0 AND NASIPAddress= '%s' AND AcctStartTime <= '%s'", sql->config->sql_acct_table, sqlrecord->AcctTimeStamp, sqlrecord->AcctTimeStamp, sqlrecord->AcctTerminateCause, sqlrecord->AcctDelayTime, sqlrecord->NASIPAddress, sqlrecord->AcctTimeStamp);
+		sprintf(querystr, "UPDATE %s SET AcctStopTime='%s', "
+		  "AcctSessionTime=unix_timestamp('%s') - unix_timestamp(AcctStartTime),"
+		  " CiscoDisconnectCause = %lu, AcctStopDelay = %lu "
+		  "WHERE AcctSessionTime=0 AND AcctStopTime=0 AND "
+		  "NASIPAddress= '%s' AND AcctStartTime <= '%s'",
+		   sql->config->sql_acct_table, sqlrecord->AcctTimeStamp, 
+		   sqlrecord->AcctTimeStamp, 
+		   sqlrecord->CiscoDisconnectCause, sqlrecord->AcctDelayTime,
+		   sqlrecord->NASIPAddress, sqlrecord->AcctTimeStamp);
 
 		if (!sql_query(socket, querystr)) {
 			log(L_ERR, "Acct: Couldn't update SQL accounting after NAS reboot - %s", sql_error(socket));
@@ -488,7 +500,12 @@
 	} 
 
 	if (sqlrecord->AcctStatusTypeId == PW_STATUS_ALIVE) {
-		sprintf(querystr, "UPDATE %s SET FramedIPAddress = '%s' WHERE AcctSessionId = '%s' AND UserName = '%s' AND NASIPAddress= '%s'", sql->config->sql_acct_table, sqlrecord->FramedIPAddress, sqlrecord->AcctSessionId, sqlrecord->UserName, sqlrecord->NASIPAddress);
+		sprintf(querystr, "UPDATE %s SET FramedIPAddress = '%s' "
+		 "WHERE AcctSessionId = '%s' AND UserName = '%s' AND "
+		 "NASIPAddress= '%s'", 
+		 sql->config->sql_acct_table, sqlrecord->FramedIPAddress, 
+		 sqlrecord->AcctSessionId, sqlrecord->UserName, 
+		 sqlrecord->NASIPAddress);
 		if (!sql_query(socket, querystr)) {
 			log(L_ERR, "Acct: Couldn't update SQL accounting for ALIVE packet - %s", sql_error(socket));
 			ret = 0;
@@ -507,7 +524,10 @@
 	if(sqlrecord->AcctStatusTypeId == PW_STATUS_START) {
              
 		/* Set start time on record with only a stop record */
-		snprintf(querystr, 2048, "UPDATE %s SET AcctStartTime = '%s', AcctStartDelay = %ld WHERE AcctSessionId = '%s' AND UserName = '%s' AND NASIPAddress = '%s' AND NASPortId = '%ld'", 
+		snprintf(querystr, 2048, 
+		"UPDATE %s SET AcctStartTime = '%s', AcctStartDelay = %lu "
+		"WHERE AcctSessionId = '%s' AND UserName = '%s' AND "
+		"NASIPAddress = '%s' AND NASPortId = %lu", 
 		sql->config->sql_acct_table,
 		sqlrecord->AcctTimeStamp,
 		sqlrecord->AcctDelayTime,
@@ -527,24 +547,34 @@
 		if (num == 0 && ret > 0) {
 
 			/* Insert new record with blank stop time until we receive the stop record */
-			snprintf(querystr, 2048, "INSERT INTO %s VALUES (0, '%s', '%s', '%s', '%s', %ld, '%s', '%s', 0, 0, '%s', '%s', 0, 0, '%s', '%s', '', '%s', '%s', '%s', %ld, 0)",
-			sql->config->sql_acct_table,
-			sqlrecord->AcctSessionId,
-			sqlrecord->UserName,
-			sqlrecord->Realm,
-			sqlrecord->NASIPAddress,
-			sqlrecord->NASPortId,
-			sqlrecord->NASPortType,
-			sqlrecord->AcctTimeStamp,
-			sqlrecord->AcctAuthentic,
-			sqlrecord->ConnectInfo,
-			sqlrecord->CalledStationId,
-			sqlrecord->CallingStationId,
-			sqlrecord->ServiceType,
-			sqlrecord->FramedProtocol,
-			sqlrecord->FramedIPAddress,
-			sqlrecord->AcctDelayTime
-			);                  
+			snprintf(querystr, 2048, "INSERT INTO %s VALUES "
+			 "(0, '%s', '%s', '%s', "
+			 "'%s', %lu, %lu, "
+			 "'%s', 0, 0, "
+			 "%lu,  0, 0, '', "
+			 "%lu, %lu, '', "
+			 "%lu, 0, 0, 0, '%s', '%s')",
+			 sql->config->sql_acct_table,
+			
+			 sqlrecord->AcctSessionId,
+			 sqlrecord->UserName,
+			 sqlrecord->Realm,
+			
+			 sqlrecord->NASIPAddress,
+			 sqlrecord->NASPortId,
+			 sqlrecord->NASPortType,
+			
+			 sqlrecord->AcctTimeStamp,
+			
+			 sqlrecord->AcctAuthentic,
+			
+			 sqlrecord->ServiceType,
+			 sqlrecord->FramedProtocol,
+			
+			 sqlrecord->AcctDelayTime,
+			 
+			 sqlrecord->CallingStationID,
+			 sqlrecord->CalledStationID );                  
 	
 			if (!sql_query(socket, querystr)) {
 				log(L_ERR, "Acct: Couldn't insert SQL accounting START record - %s", sql_error(socket));
@@ -563,7 +593,10 @@
 		else
 			sprintf(authstr, "UserName = '%s'", sqlrecord->UserName);
 
-		sprintf(querystr, "SELECT RadAcctId FROM %s WHERE AcctSessionId='%s' AND NASIPAddress='%s' AND %s", sql->config->sql_acct_table, sqlrecord->AcctSessionId, sqlrecord->NASIPAddress, authstr);
+		sprintf(querystr, "SELECT RadAcctId FROM %s WHERE "
+		  "AcctSessionId='%s' AND NASIPAddress='%s' AND %s", 
+		  sql->config->sql_acct_table, 
+		  sqlrecord->AcctSessionId, sqlrecord->NASIPAddress, authstr);
 		sql_select_query(socket, querystr);
 		num = sql_num_rows(socket);
 		sql_finish_select_query(socket);
@@ -571,19 +604,25 @@
 		if (num > 0) {
 
 			/* Set stop time on matching record with start time */
-			snprintf(querystr, 2048, "UPDATE %s SET AcctStopTime = '%s', AcctSessionTime = '%lu', AcctInputOctets = '%lu', AcctOutputOctets = '%lu', AcctTerminateCause = '%s', AcctStopDelay = %ld WHERE AcctSessionId = '%s' AND UserName = '%s' AND NASIPAddress = '%s' AND NASPortId = '%ld'", 
-			sql->config->sql_acct_table,
-			sqlrecord->AcctTimeStamp,
-			sqlrecord->AcctSessionTime,
-			sqlrecord->AcctInputOctets,
-			sqlrecord->AcctOutputOctets,
-			sqlrecord->AcctTerminateCause,
-			sqlrecord->AcctDelayTime,
-			sqlrecord->AcctSessionId,
-			sqlrecord->UserName,
-			sqlrecord->NASIPAddress,
-			sqlrecord->NASPortId
-			);
+			snprintf(querystr, 2048, 
+			 "UPDATE %s SET "
+			 "AcctStopTime = '%s', AcctSessionTime = %lu, "
+			 "AcctInputOctets = %lu, AcctOutputOctets = %lu, "
+			 "FramedIPAddress = '%s', CiscoDisconnectCause = %lu, "
+			 "AcctStopDelay = %lu, "
+			 "CiscoDataRate = %lu, CiscoXmitRate = %lu, "
+			 "CallingStationID = '%s', CalledStationID = '%s' "
+			 "WHERE AcctSessionId = '%s' AND UserName = '%s' AND "
+			 "NASIPAddress = '%s' AND NASPortId = %lu", 
+			 sql->config->sql_acct_table,
+			 sqlrecord->AcctTimeStamp, sqlrecord->AcctSessionTime,
+			 sqlrecord->AcctInputOctets, sqlrecord->AcctOutputOctets,
+			 sqlrecord->FramedIPAddress, sqlrecord->CiscoDisconnectCause,
+			 sqlrecord->AcctDelayTime,
+			 sqlrecord->CiscoDataRate, sqlrecord->CiscoXmitRate,
+			 sqlrecord->CallingStationID,sqlrecord->CalledStationID,
+			 sqlrecord->AcctSessionId, sqlrecord->UserName,
+			 sqlrecord->NASIPAddress, sqlrecord->NASPortId);
 
 			if (!sql_query(socket, querystr)) {
 				log(L_ERR, "Acct: Couldn't update SQL accounting STOP record - %s", sql_error(socket));
@@ -607,28 +646,42 @@
 #endif /* CISCO_ACCOUNTING_HACK */
             
 			/* Insert record with no start time until matching start record comes */
-			snprintf(querystr, 2048, "INSERT INTO %s VALUES (0, '%s', '%s', '%s', '%s', %ld, '%s', 0, '%s', '%lu', '%s', '%s', '%lu', '%lu', '%s', '%s', '%s', '%s', '%s', '%s', 0, %ld)",
+			snprintf(querystr, 2048, "INSERT INTO %s VALUES "
+			"(0, '%s', '%s', '%s', "
+			"'%s', %lu, %lu, "
+			"0, '%s', %lu, "
+			"%lu, %lu, %lu, "
+			"%lu, %lu, "
+			"%lu, '%s', "
+			"0, %lu, %lu, %lu, '%s', '%s')",
 			sql->config->sql_acct_table,
+			
 			sqlrecord->AcctSessionId,
 			sqlrecord->UserName,
 			sqlrecord->Realm,
+			
 			sqlrecord->NASIPAddress,
 			sqlrecord->NASPortId,
 			sqlrecord->NASPortType,
+			
 			sqlrecord->AcctTimeStamp,
 			sqlrecord->AcctSessionTime,
+			
 			sqlrecord->AcctAuthentic,
-			sqlrecord->ConnectInfo,
 			sqlrecord->AcctInputOctets,
 			sqlrecord->AcctOutputOctets,
-			sqlrecord->CalledStationId,
-			sqlrecord->CallingStationId,
-			sqlrecord->AcctTerminateCause,
+			
+			sqlrecord->CiscoDisconnectCause,
 			sqlrecord->ServiceType,
+			
 			sqlrecord->FramedProtocol,
 			sqlrecord->FramedIPAddress,
-			sqlrecord->AcctDelayTime
-			);                  
+			
+			sqlrecord->AcctDelayTime,
+			sqlrecord->CiscoDataRate,
+			sqlrecord->CiscoXmitRate,
+			sqlrecord->CallingStationID,
+			sqlrecord->CalledStationID);                  
 
 			if (!sql_query(socket, querystr)) {
 				log(L_ERR, "Acct: Couldn't insert SQL accounting STOP record - %s", sql_error(socket));
