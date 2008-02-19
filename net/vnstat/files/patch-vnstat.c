--- src/vnstat.c.orig	2008-02-01 23:11:50.000000000 +0100
+++ src/vnstat.c	2008-02-18 18:18:30.000000000 +0100
@@ -524,8 +524,8 @@
 		if (files==0) {
 			printf("No database found, nothing to do. Use --help for help.\n\n");
 			printf("A new database can be created with the following command:\n");
-			printf("    %s -u -i eth0\n\n", argv[0]);
-			printf("Replace 'eth0' with the interface that should be monitored. A list\n");
+			printf("    %s -u -i fxp0\n\n", argv[0]);
+			printf("Replace 'fxp0' with the interface that should be monitored. A list\n");
 			printf("of available interfaces can be seen with the 'ifconfig' command.\n");
 		} else {
 			printf("Nothing to do. Use --help for help.\n");
