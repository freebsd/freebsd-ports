--- plugins/check_snmp.c.orig	Thu Feb 28 07:42:59 2002
+++ plugins/check_snmp.c	Sun Jul 14 17:21:03 2002
@@ -145,8 +145,8 @@
 	/* create the command line to execute */
 	command_line = ssprintf
 		(command_line,
-		 "%s -m ALL -v 1 %s %s %s",
-		 PATH_TO_SNMPGET, server_address, community, oid);
+		 "%s -m ALL -v 1 -c %s %s %s",
+		 PATH_TO_SNMPGET, community, server_address, oid);
 
 	/* run the command */
 	child_process = spopen (command_line);
