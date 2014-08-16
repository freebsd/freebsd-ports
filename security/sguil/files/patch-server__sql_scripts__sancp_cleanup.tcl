--- server/sql_scripts/sancp_cleanup.tcl.orig	2011-08-11 20:31:07.000000000 +0000
+++ server/sql_scripts/sancp_cleanup.tcl	2011-08-11 20:31:26.000000000 +0000
@@ -214,7 +214,7 @@
     INDEX dst_port (dst_port),                         \
     INDEX src_port (src_port),                         \
     INDEX start_time (start_time)                      \
-    ) TYPE=MERGE UNION=([join $tmpTables ,])      \
+    ) ENGINE=MERGE UNION=([join $tmpTables ,])      \
     "
 # Create our MERGE sancp table
 mysqlexec $dbSocketID $createQuery
