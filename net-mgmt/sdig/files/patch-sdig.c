--- sdig.c.orig	Mon Mar 24 13:08:00 2003
+++ sdig.c	Wed May 19 13:17:43 2004
@@ -426,7 +426,7 @@
 
 static void do_ifdescr(stype *sw, long port)
 {
-	char	query[256], *ifdescr;
+	char	query[256], *ifdescr, *ifname;
 	long	ifnum;
 
 	/* first get the switch's ifnum for the port */
@@ -437,13 +437,28 @@
 	if (ifnum == -1)
 		return;
 
-	snprintf(query, sizeof(query), "interfaces.ifTable.ifEntry.ifDescr.%ld",
+	snprintf(query, sizeof(query), "IF-MIB::ifName.%ld",
+		ifnum);
+
+	ifname = snmpget_str(sw->ip, sw->pw, query);
+
+	if (!ifname) {
+		snprintf(query, sizeof(query), "IF-MIB::ifAlias.%ld", ifnum);
+		snmpget_str(sw->ip, sw->pw, query);
+	}
+
+	snprintf(query, sizeof(query), "IF-MIB::ifDescr.%ld",
 		ifnum);
 
 	ifdescr = snmpget_str(sw->ip, sw->pw, query);
 
+	if (ifname) {
+		printf(" (%s)", ifname);
+		free(ifname);
+	}
+
 	if (ifdescr) {
-		printf(" (%s)", ifdescr);
+		printf(" [%s]", ifdescr);
 		free(ifdescr);
 	}
 }
