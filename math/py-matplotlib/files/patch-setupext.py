--- setupext.py.orig	Thu Jan 27 17:47:41 2005
+++ setupext.py	Thu Jan 27 17:49:08 2005
@@ -37,6 +37,8 @@
     'linux'  : ['/usr/local', '/usr',],
     'darwin' : ['/usr/local', '/usr', '/sw', '/usr/X11R6'],
     'freebsd4' : ['/usr/local', '/usr'],
+    'freebsd5' : ['/usr/local', '/usr'],
+    'freebsd6' : ['/usr/local', '/usr'],
     'sunos5' : [os.getenv('MPLIB_BASE') or '/usr/local',],
 }
 
@@ -302,7 +304,7 @@
     o = find_tcltk()
     module.include_dirs.extend([o.tcl_inc, o.tk_inc])
     module.library_dirs.extend([o.tcl_lib, o.tk_lib])
-    module.libraries.extend(['tk'+o.tkv, 'tcl'+o.tkv])
+    module.libraries.extend(['tk84', 'tcl84'])
 
 
 def add_windowing_flags(module):
