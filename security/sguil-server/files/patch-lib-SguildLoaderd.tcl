--- lib/SguildLoaderd.tcl.orig	2007-09-25 14:17:13.000000000 +0000
+++ lib/SguildLoaderd.tcl	2011-08-11 20:22:18.000000000 +0000
@@ -129,7 +129,7 @@
         INDEX dst_port (dst_port),                         \
         INDEX src_port (src_port),                         \
         INDEX start_time (start_time)                      \
-        )                                                  \
+        ) ENGINE=MyISAM                                    \
         "

     # Create the table
@@ -182,7 +182,7 @@
         INDEX dst_port (dst_port),                         \
         INDEX src_port (src_port),                         \
         INDEX start_time (start_time)                      \
-        ) TYPE=MERGE UNION=([join $tmpTables ,])      \
+        ) ENGINE=MERGE UNION=([join $tmpTables ,])      \
         "
     # Create our MERGE sancp table
     mysqlexec $dbSocketID $createQuery
@@ -225,7 +225,7 @@
     } else {
         # Make sure its a MERGE table and not the old monster
         set tableStatus [mysqlsel $LOADERD_DB_ID {SHOW TABLE STATUS LIKE 'sancp'} -flatlist]
-        if { [lindex $tableStatus 1] != "MRG_MyISAM" } {
+        if { [lindex $tableStatus 1] != "MRG_MYISAM" } {
             ErrorMessage "ERROR: loaderd: You appear to be using an old version of the\n\
                           sguil database schema that does not support the MERGE sancp\n\
                           table. Please see the CHANGES document for more information\n."
