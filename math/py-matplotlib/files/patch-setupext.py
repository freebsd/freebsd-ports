--- setupext.py.orig	Tue Mar 29 19:25:37 2005
+++ setupext.py	Sat Nov  5 20:26:49 2005
@@ -38,7 +38,8 @@
     'darwin' : ['/usr/local', '/usr', '/sw', '/usr/X11R6'],
     'freebsd4' : ['/usr/local', '/usr'],
     'freebsd5' : ['/usr/local', '/usr'],
-    'freebsd6' : ['/usr/local', '/usr'],    
+    'freebsd6' : ['/usr/local', '/usr'],
+    'freebsd7' : ['/usr/local', '/usr'],
     'sunos5' : [os.getenv('MPLIB_BASE') or '/usr/local',],
 }
 
@@ -306,9 +307,9 @@
 
     # you're still here? ok we'll try it this way
     o = find_tcltk() # todo: try/except
-    module.include_dirs.extend([o.tcl_inc, o.tk_inc])
+    module.include_dirs.extend(["/usr/local/include/tcl8.4", "/usr/local/include/tk8.4"])
     module.library_dirs.extend([o.tcl_lib, o.tk_lib])
-    module.libraries.extend(['tk'+o.tkv, 'tcl'+o.tkv])
+    module.libraries.extend(['tk84', 'tcl84'])
 
 
 def add_windowing_flags(module):
