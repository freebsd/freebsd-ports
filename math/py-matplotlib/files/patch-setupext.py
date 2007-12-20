--- setupext.py.orig	2007-02-01 04:32:51.000000000 -0500
+++ setupext.py	2007-12-19 21:26:33.000000000 -0500
@@ -50,9 +50,11 @@
     'cygwin' : ['/usr/local', '/usr',],
     'darwin' : ['/sw/lib/freetype2', '/sw/lib/freetype219', '/usr/local',
                 '/usr', '/sw'],
-    'freebsd4' : ['/usr/local', '/usr'],
-    'freebsd5' : ['/usr/local', '/usr'],
-    'freebsd6' : ['/usr/local', '/usr'],
+    'freebsd4' : ['%%LOCALBASE%%', '/usr'],
+    'freebsd5' : ['%%LOCALBASE%%', '/usr'],
+    'freebsd6' : ['%%LOCALBASE%%', '/usr'],
+    'freebsd7' : ['%%LOCALBASE%%', '/usr'],
+    'freebsd8' : ['%%LOCALBASE%%', '/usr'],
     'sunos5' : [os.getenv('MPLIB_BASE') or '/usr/local',],
     'gnukfreebsd5' : ['/usr/local', '/usr'],
     'gnukfreebsd6' : ['/usr/local', '/usr'],
@@ -455,9 +457,9 @@
 
     # you're still here? ok we'll try it this way
     o = find_tcltk() # todo: try/except
-    module.include_dirs.extend([o.tcl_inc, o.tk_inc])
+    module.include_dirs.extend(["%%TCL_INCLUDEDIR%%", "%%TK_INCLUDEDIR%%"])
     module.library_dirs.extend([o.tcl_lib, o.tk_lib])
-    module.libraries.extend(['tk'+o.tkv, 'tcl'+o.tkv])
+    module.libraries.extend(['tk%%USE_TK%%', 'tcl%%USE_TCL%%'])
 
 
 def add_windowing_flags(module):
