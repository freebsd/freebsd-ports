--- server/lib/SguildMysqlMerge.tcl.orig	2012-10-12 21:18:22.000000000 +0000
+++ server/lib/SguildMysqlMerge.tcl	2012-10-12 21:19:41.000000000 +0000
@@ -9,7 +9,7 @@
         set tmpQry "SHOW TABLE STATUS LIKE '$tableName'"
         set tableStatus [mysqlsel $MAIN_DB_SOCKETID $tmpQry -flatlist]
 
-        if { $tableStatus != "" && ![ string equal -nocase [lindex $tableStatus 1] "MRG_MyISAM" ] } {
+        if { $tableStatus != "" && ![ string equal -nocase [lindex $tableStatus 1] "MRG_MYISAM" ] } {
 
             # Non MERGE table found.
             set errorMsg "\n*************************************************************\n
