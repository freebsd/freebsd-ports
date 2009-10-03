--- ./spamd/grey.c.orig
+++ ./spamd/grey.c
@@ -329,9 +329,10 @@
 {
 	ipfw_table_entry ent;
 	int i;
-	static int ipfw_socket;
+	static int ipfw_socket = 0;
 	
-	ipfw_socket = socket(AF_INET, SOCK_RAW, IPPROTO_RAW);
+	if (ipfw_socket == 0)
+		ipfw_socket = socket(AF_INET, SOCK_RAW, IPPROTO_RAW);
 
 	if (debug)
 		fprintf(stderr, "configure ipfw tabno: %d\n", ipfw_tabno);
@@ -363,8 +364,11 @@
 		inet_aton(addrs[i], (struct in_addr *)&ent.addr);
 		if (setsockopt(ipfw_socket, IPPROTO_IP, IP_FW_TABLE_ADD,  &ent, sizeof(ent)) < 0)
 		{
-			syslog_r(LOG_INFO, &sdata, "IPFW setsockopt(IP_FW_TABLE_ADD) (%m)");
-			return(-1);
+			/* work around dups */
+			if (errno != EEXIST) {
+				syslog_r(LOG_INFO, &sdata, "IPFW setsockopt(IP_FW_TABLE_ADD) (%m)");
+				return(-1);
+			}
 		}
 	}
 
