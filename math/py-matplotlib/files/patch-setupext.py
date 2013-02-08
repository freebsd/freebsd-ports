--- setupext.py.orig	2011-10-06 15:50:23.000000000 +0100
+++ setupext.py	2012-03-22 23:29:06.881660702 +0000
@@ -1080,9 +1080,12 @@
 
         # Add final versions of directories and libraries to module lists
         tcl_lib_dir, tcl_inc_dir, tcl_lib, tk_lib_dir, tk_inc_dir, tk_lib = result
-        module.include_dirs.extend([tcl_inc_dir, tk_inc_dir])
-        module.library_dirs.extend([tcl_lib_dir, tk_lib_dir])
-        module.libraries.extend([tcl_lib, tk_lib])
+        #module.include_dirs.extend([tcl_inc_dir, tk_inc_dir])
+        #module.library_dirs.extend([tcl_lib_dir, tk_lib_dir])
+        #module.libraries.extend([tcl_lib, tk_lib])
+        module.include_dirs.extend(["/usr/local/include/tcl8.5", "/usr/local/include/tk8.5"])
+        module.library_dirs.extend(["/usr/local/lib/tcl8.5", "/usr/local/lib/tk8.5"])
+        module.libraries.extend(['tk' + "85", 'tcl' + "85"])
 
     return message
 
