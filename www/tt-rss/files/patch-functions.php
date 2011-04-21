--- ./functions.php.orig	2011-04-21 13:52:41.000000000 +0200
+++ ./functions.php	2011-04-21 22:13:21.000000000 +0200
@@ -7348,9 +7348,9 @@
 
 		if ($query) {
 			if (DB_TYPE == "pgsql") {
-				$query .= " AND ttrss_entries.date_entered > NOW() - INTERVAL '30 days'";
+				$query = " ($query) AND ttrss_entries.date_entered > NOW() - INTERVAL '14 days'";
 			} else {
-				$query .= " AND ttrss_entries.date_entered > DATE_SUB(NOW(), INTERVAL 30 DAY";
+				$query = " ($query) AND ttrss_entries.date_entered > DATE_SUB(NOW(), INTERVAL 14 DAY";
 			}
 			$query .= " AND ";
 		}
