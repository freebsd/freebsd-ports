--- pmlist.cpp.orig	Fri May  3 00:16:28 2002
+++ pmlist.cpp	Sat Aug  3 22:11:41 2002
@@ -30,6 +30,9 @@
 #include <stdlib.h>
 #include <unistd.h>
 #include <iostream.h>
+
+extern char *ExtIf;
+
 PortMapList::PortMapList()
 {
 
@@ -190,9 +193,12 @@
 	else
 		strcpy (prt, "udp");
 
-	sprintf(command,"/usr/sbin/iptables -t nat -A PREROUTING -p %s -d %s --dport %d -j DNAT --to %s:%d", prt, ExtIP, ExtPort, IntIP, IntPort);
-	
-	system(command);
+	FILE *ipnat = popen("/sbin/ipnat -f -", "w");
+	if (ipnat == NULL)
+		return 0;
+	sprintf(command, "rdr %s %s/32 port %d -> %s port %d %s", ExtIf, ExtIP, ExtPort, IntIP, IntPort, prt);
+	fprintf(ipnat, command);
+	pclose(ipnat);
 
 	ret=1;
 	return (ret);
@@ -234,9 +240,13 @@
 	else
 		strcpy (prt, "udp");
 
-	sprintf(command, "/usr/sbin/iptables -t nat -D PREROUTING -p %s -d %s --dport %d -j DNAT --to %s:%d", prt, ExtIP, ExtPort, IntIP, IntPort);
-	
-	system(command);
+	FILE *ipnat = popen("/sbin/ipnat -rf -", "w");
+	if (ipnat == NULL)
+		return 0;
+	sprintf(command, "rdr %s %s/32 port %d -> %s port %d %s", ExtIf, ExtIP, ExtPort, IntIP, IntPort, prt);
+	fprintf(ipnat, command);
+	pclose(ipnat);
+
 	ret = 1;
 
 	return (ret);
