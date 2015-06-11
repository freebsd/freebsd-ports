--- server/sql_scripts/sancp_cleanup.tcl.orig	2014-03-29 00:41:36 UTC
+++ server/sql_scripts/sancp_cleanup.tcl
@@ -214,7 +214,7 @@ set createQuery "                       
     INDEX dst_port (dst_port),                         \
     INDEX src_port (src_port),                         \
     INDEX start_time (start_time)                      \
-    ) TYPE=MERGE UNION=([join $tmpTables ,])      \
+    ) ENGINE=MERGE UNION=([join $tmpTables ,])      \
     "
 # Create our MERGE sancp table
 mysqlexec $dbSocketID $createQuery
