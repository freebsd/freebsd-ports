--- plugins/check_mysql.c.orig	Sun Dec 26 00:17:44 2004
+++ plugins/check_mysql.c	Sun Feb 20 14:12:10 2005
@@ -123,8 +123,16 @@
 				die (STATE_CRITICAL, "%s\n", slaveresult);
 			}
 
+		} else if (mysql_field_count (&mysql) == 33) {
+			/* mysql >= 4.1.1 */
+			snprintf (slaveresult, SLAVERESULTSIZE, "Slave IO: %s Slave SQL: %s", row[10], row[11]);
+			if (strcmp (row[10], "Yes") != 0 || strcmp (row[11], "Yes") != 0) {
+				mysql_free_result (res);
+				mysql_close (&mysql);
+				die (STATE_CRITICAL, "%s\n", slaveresult);
+			}
 		} else {
-			/* mysql 4.x.x */
+			/* mysql 4.0.x or 4.1.0 */
 			snprintf (slaveresult, SLAVERESULTSIZE, "Slave IO: %s Slave SQL: %s", row[9], row[10]);
 			if (strcmp (row[9], "Yes") != 0 || strcmp (row[10], "Yes") != 0) {
 				mysql_free_result (res);
