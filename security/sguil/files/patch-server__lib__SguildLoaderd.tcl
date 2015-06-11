--- server/lib/SguildLoaderd.tcl.orig	2014-03-29 00:41:36 UTC
+++ server/lib/SguildLoaderd.tcl
@@ -220,7 +220,7 @@ proc InitLoaderd {} {
     } else {
         # Make sure its a MERGE table and not the old monster
         set tableStatus [mysqlsel $LOADERD_DB_ID {SHOW TABLE STATUS LIKE 'sancp'} -flatlist]
-        if { $tableStatus != "" && ![ string equal -nocase [lindex $tableStatus 1] "MRG_MyISAM" ] } {
+        if { $tableStatus != "" && ![ string equal -nocase [lindex $tableStatus 1] "MRG_MYISAM" ] } {
 
             ErrorMessage "ERROR: loaderd: You appear to be using an old version of the\n\
                           sguil database schema that does not support the MERGE sancp\n\
