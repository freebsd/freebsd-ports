--- pmlist.cpp.orig	Fri Jan  3 03:14:24 2003
+++ pmlist.cpp	Mon Jan 20 20:38:16 2003
@@ -31,6 +31,8 @@
 #include <unistd.h>
 #include <iostream>
 
+extern char *ExtIf;
+
 PortMapList::PortMapList()
 {
 
@@ -182,8 +184,13 @@
 {
 	char command[255];
 
-	sprintf(command,"/usr/sbin/iptables -t nat -A PREROUTING -p %s -d %s --dport %d -j DNAT --to %s:%d", Proto, ExtIP, ExtPort, IntIP, IntPort);
-	system(command);
+	FILE *ipnat = popen("/sbin/ipnat -f -", "w");
+	if (ipnat == NULL)
+		return 0;
+	sprintf(command, "rdr %s %s/32 port %d -> %s port %d %s",
+		ExtIf, ExtIP, ExtPort, IntIP, IntPort, Proto);
+	fprintf(ipnat, command);
+	pclose(ipnat);
 
 	return (1);
 }
@@ -218,9 +225,14 @@
 {
 	char command[255];
 	
+	FILE *ipnat = popen("/sbin/ipnat -rf -", "w");
+	if (ipnat == NULL)
+		return 0;
+	sprintf(command, "rdr %s %s/32 port %d -> %s port %d %s",
+		ExtIf, ExtIP, ExtPort, IntIP, IntPort, Proto);
+	fprintf(ipnat, command);
+	pclose(ipnat);
 
-	sprintf(command, "/usr/sbin/iptables -t nat -D PREROUTING -p %s -d %s --dport %d -j DNAT --to %s:%d", Proto, ExtIP, ExtPort, IntIP, IntPort);
-	system(command);	
 	return (1);
 }
 
