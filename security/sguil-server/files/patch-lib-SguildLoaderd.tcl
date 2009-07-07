--- lib/SguildLoaderd.tcl.bak	2009-07-06 14:53:16.000000000 -0500
+++ lib/SguildLoaderd.tcl	2009-07-06 14:53:56.000000000 -0500
@@ -225,7 +225,7 @@
     } else {
         # Make sure its a MERGE table and not the old monster
         set tableStatus [mysqlsel $LOADERD_DB_ID {SHOW TABLE STATUS LIKE 'sancp'} -flatlist]
-        if { [lindex $tableStatus 1] != "MRG_MyISAM" } {
+        if { [lindex $tableStatus 1] != "MRG_MYISAM" } {
             ErrorMessage "ERROR: loaderd: You appear to be using an old version of the\n\
                           sguil database schema that does not support the MERGE sancp\n\
                           table. Please see the CHANGES document for more information\n."
