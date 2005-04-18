--- setupext.py.orig	Tue Apr 12 16:09:32 2005
+++ setupext.py	Tue Apr 12 16:10:28 2005
@@ -308,7 +308,7 @@
     o = find_tcltk() # todo: try/except
-    module.include_dirs.extend([o.tcl_inc, o.tk_inc])
+    module.include_dirs.extend(["/usr/local/include/tcl8.4", "/usr/local/include/tk8.4"])
     module.library_dirs.extend([o.tcl_lib, o.tk_lib])
-    module.libraries.extend(['tk'+o.tkv, 'tcl'+o.tkv])
+    module.libraries.extend(['tk84', 'tcl84'])
 
 
 def add_windowing_flags(module):
