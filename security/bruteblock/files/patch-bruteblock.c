--- bruteblock.c.orig	2006-08-20 08:22:37.000000000 +0200
+++ bruteblock.c	2014-10-15 16:19:19.000000000 +0200
@@ -99,7 +99,7 @@
 				snprintf(table, sizeof(table), "%d", ipfw2_table_no);
 				argv[1] = table;
 				argv[2] = command;
-				snprintf(utime, sizeof(utime), "%d",
-				time(NULL) + reset_ip);
+				snprintf(utime, sizeof(utime), "%lld",
+				(long long)(time(NULL) + reset_ip));
 				argv[4] = utime;
 				argv[3] = host;
