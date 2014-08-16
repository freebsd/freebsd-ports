--- server/lib/SguildLoaderd.tcl.orig	2012-10-12 21:07:19.000000000 +0000
+++ server/lib/SguildLoaderd.tcl	2012-10-12 21:15:06.000000000 +0000
@@ -220,7 +220,7 @@
     } else {
         # Make sure its a MERGE table and not the old monster
         set tableStatus [mysqlsel $LOADERD_DB_ID {SHOW TABLE STATUS LIKE 'sancp'} -flatlist]
-        if { $tableStatus != "" && ![ string equal -nocase [lindex $tableStatus 1] "MRG_MyISAM" ] } {
+        if { $tableStatus != "" && ![ string equal -nocase [lindex $tableStatus 1] "MRG_MYISAM" ] } {
 
             ErrorMessage "ERROR: loaderd: You appear to be using an old version of the\n\
                           sguil database schema that does not support the MERGE sancp\n\
