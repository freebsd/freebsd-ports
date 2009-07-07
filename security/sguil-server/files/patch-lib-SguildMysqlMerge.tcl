--- lib/SguildMysqlMerge.tcl.bak	2009-07-06 14:53:27.000000000 -0500
+++ lib/SguildMysqlMerge.tcl	2009-07-06 14:54:26.000000000 -0500
@@ -9,7 +9,7 @@
         set tmpQry "SHOW TABLE STATUS LIKE '$tableName'"
         set tableStatus [mysqlsel $MAIN_DB_SOCKETID $tmpQry -flatlist]
 
-        if { $tableStatus != "" && [lindex $tableStatus 1] != "MRG_MyISAM" } {
+        if { $tableStatus != "" && [lindex $tableStatus 1] != "MRG_MYISAM" } {
 
             # Non MERGE table found.
             set errorMsg "\n*************************************************************\n
