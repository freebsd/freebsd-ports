--- poller.c.orig	Wed Oct 12 03:13:48 2005
+++ poller.c	Thu Nov 10 11:30:49 2005
@@ -455,9 +455,9 @@
 					(strcmp(last_snmp_password, poller_items[i].snmp_password) != 0)) {
 					
 					if (num_oids > 0) {
+						int j;
 						snmp_get_multi(host, snmp_oids, num_oids);
 
-						int j;
 						for (j = 0; j < num_oids; j++) {
 							if (host->ignore_host) {
 								snprintf(logmessage, LOGSIZE-1, "Host[%i] DS[%i] WARNING: SNMP timeout detected [%i ms], ignoring host '%s'\n", host_id, poller_items[snmp_oids[j].array_position].local_data_id, host->snmp_timeout, host->hostname);
@@ -500,9 +500,9 @@
 				}
 
 				if (num_oids > set.max_get_size) {
+					int j;
 					snmp_get_multi(host, snmp_oids, num_oids);
 
-					int j;
 					for (j = 0; j < num_oids; j++) {
 						if (host->ignore_host) {
 							snprintf(logmessage, LOGSIZE-1, "Host[%i] DS[%i] WARNING: SNMP timeout detected [%i ms], ignoring host '%s'\n", host_id, poller_items[snmp_oids[j].array_position].local_data_id, host->snmp_timeout, host->hostname);
@@ -617,9 +617,9 @@
 
 	/* process last bulk request if applicable */
 	if (num_oids > 0) {
+		int j;
 		snmp_get_multi(host, snmp_oids, num_oids);
 
-		int j;
 		for (j = 0; j < num_oids; j++) {
 			if (host->ignore_host) {
 				snprintf(logmessage, LOGSIZE-1, "Host[%i] DS[%i] WARNING: SNMP timeout detected [%i ms], ignoring host '%s'\n", host_id, poller_items[snmp_oids[j].array_position].local_data_id, host->snmp_timeout, host->hostname);
@@ -648,9 +648,12 @@
 		}
 	}
 	
+	{
 	/* format database insert */
 	int buffer;
 	char result_string[BUFSIZE];
+	char delim = ' ';
+
 	buffer = 600*rows_processed+100;
 
 	if (!(query3 = (char *)malloc(buffer))) {
@@ -662,12 +665,12 @@
 	snprintf(query3, buffer-1, "INSERT INTO poller_output (local_data_id,rrd_name,time,output) VALUES");
 
 	i=0;
-	char delim = ' ';
 	while (i < rows_processed) {
 		snprintf(result_string, sizeof(result_string)-1, "%c(%i,'%s','%s','%s')", delim, poller_items[i].local_data_id, poller_items[i].rrd_name, start_datetime, poller_items[i].result);
 		strncat(query3, result_string, strlen(result_string));
 		delim = ',';
 		i++;
+	}
 	}
 
 	/* only perform and insert if there is something to insert */
--- snmp.c.orig	Wed Oct 12 03:13:48 2005
+++ snmp.c	Thu Nov 10 11:25:26 2005
@@ -306,9 +306,9 @@
 					}
 				}else {
 					if (response->errindex != 0) {
+						int count;
 						/* removed errored OID and then retry */
 						snprintf(snmp_oids[response->errindex].result, sizeof(snmp_oids[response->errindex].result)-1, "U");
-						int count;
 						for (count = 1, vars = response->variables;
 							vars && count != response->errindex;
 							vars = vars->next_variable, count++) {
