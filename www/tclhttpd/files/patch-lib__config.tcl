--- lib/config.tcl	2000-08-02 03:06:52.000000000 -0400
+++ lib/config.tcl	2016-06-05 14:51:18.000000000 -0400
@@ -52,6 +52,9 @@
 
     set i [interp create -safe]
     interp expose $i file
+    foreach subcommand {isdirectory exists dirname} {
+      interp alias $i ::tcl::file::$subcommand {} file $subcommand
+    }
 
