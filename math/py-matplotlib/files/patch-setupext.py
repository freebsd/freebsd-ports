--- setupext.py.orig	2007-12-24 13:23:32.000000000 -0500
+++ setupext.py	2008-02-22 12:23:24.000000000 -0500
@@ -52,9 +52,11 @@
     'cygwin' : ['/usr/local', '/usr',],
     'darwin' : ['/sw/lib/freetype2', '/sw/lib/freetype219', '/usr/local',
                 '/usr', '/sw', '/usr/X11R6'],
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
@@ -983,9 +985,9 @@
             tk_lib = "/usr/local/lib"
             tk_ver = ""
         # Add final versions of directories and libraries to module lists
-        module.include_dirs.extend([tcl_inc, tk_inc])
-        module.library_dirs.extend([tcl_lib, tk_lib])
-        module.libraries.extend(['tk' + tk_ver, 'tcl' + tk_ver])
+        module.include_dirs.extend(["%%TCL_INCLUDEDIR%%", "%%TK_INCLUDEDIR%%"])
+        module.library_dirs.extend(["%%TCL_LIBDIR%%", "%%TK_LIBDIR%%"])
+        module.libraries.extend(['tk%%USE_TK%%', 'tcl%%USE_TCL%%'])
     
     return message
 
