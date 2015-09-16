--- server/lib/SguildMysqlMerge.tcl.orig	2014-03-29 00:41:36 UTC
+++ server/lib/SguildMysqlMerge.tcl
@@ -9,7 +9,7 @@ proc InitializeMysqlMergeTables {} {
         set tmpQry "SHOW TABLE STATUS LIKE '$tableName'"
         set tableStatus [mysqlsel $MAIN_DB_SOCKETID $tmpQry -flatlist]
 
-        if { $tableStatus != "" && ![ string equal -nocase [lindex $tableStatus 1] "MRG_MyISAM" ] } {
+        if { $tableStatus != "" && ![ string equal -nocase [lindex $tableStatus 1] "MRG_MYISAM" ] } {
 
             # Non MERGE table found.
             set errorMsg "\n*************************************************************\n
