--- plugins/check_snmp.c.orig	Fri Jun 21 14:34:23 2002
+++ plugins/check_snmp.c	Fri Jun 21 14:33:45 2002
@@ -146,13 +146,13 @@
 	/* create the command line to execute */
 	if (getnext==TRUE) {
 		command_line = ssprintf (command_line,
-			"%s -m ALL -v 1 %s %s %s",
-			PATH_TO_SNMPGETNEXT, server_address, community, oid);
+			"%s -m ALL -v 1 -c %s %s %s",
+			PATH_TO_SNMPGETNEXT, community, server_address, oid);
 	}
 	else {
 		command_line = ssprintf (command_line,
-			"%s -m ALL -v 1 %s %s %s",
-			PATH_TO_SNMPGET, server_address, community, oid);
+			"%s -m ALL -v 1 -c %s %s %s",
+			PATH_TO_SNMPGET, community, server_address, oid);
 	}
 
 	/* run the command */
