--- setupext.py.orig    2010-07-07 05:41:55.000000000 +0400
+++ setupext.py    2011-10-16 18:49:43.000000000 +0400
@@ -68,6 +68,10 @@
     'freebsd4' : ['/usr/local', '/usr'],
     'freebsd5' : ['/usr/local', '/usr'],
     'freebsd6' : ['/usr/local', '/usr'],
+    'freebsd7' : ['/usr/local', '/usr'],
+    'freebsd8' : ['/usr/local', '/usr'],
+    'freebsd9' : ['/usr/local', '/usr'],
+    'freebsd10': ['/usr/local', '/usr'],
     'sunos5' : [os.getenv('MPLIB_BASE') or '/usr/local',],
     'gnukfreebsd5' : ['/usr/local', '/usr'],
     'gnukfreebsd6' : ['/usr/local', '/usr'],
@@ -789,7 +793,7 @@
         module.libraries.extend(wxlibs)
         return
 
-    get_pkgconfig(module, '', flags='--cppflags --libs', pkg_config_exec='wx-config')
+    get_pkgconfig(module, '', flags='--cppflags --libs', pkg_config_exec=wxconfig)
 
 # Make sure you use the Tk version given by Tkinter.TkVersion
 # or else you'll build for a wrong version of the Tcl
@@ -828,8 +832,12 @@
                 gotit = False
 
     if gotit:
+        try:
+          tk_v = Tkinter.__version__.split()[-2]
+        except (AttributeError, IndexError):
+          tk_v = 'version not identified'
         print_status("Tkinter", "Tkinter: %s, Tk: %s, Tcl: %s" %
-                     (Tkinter.__version__.split()[-2], Tkinter.TkVersion, Tkinter.TclVersion))
+                     (tk_v, Tkinter.TkVersion, Tkinter.TclVersion))
     else:
         print_status("Tkinter", "no")
     if explanation is not None:
@@ -1092,9 +1100,9 @@
 
         # Add final versions of directories and libraries to module lists
         tcl_lib, tcl_inc, tk_lib, tk_inc = result
-        module.include_dirs.extend([tcl_inc, tk_inc])
-        module.library_dirs.extend([tcl_lib, tk_lib])
-        module.libraries.extend(['tk' + tk_ver, 'tcl' + tk_ver])
+        module.include_dirs.extend(["/usr/local/include/tcl8.5", "/usr/local/include/tk8.5"])
+        module.library_dirs.extend(["/usr/local/lib/tcl8.5", "/usr/local/lib/tk8.5"])
+        module.libraries.extend(['tk' + "85", 'tcl' + "85"])
 
     return message
 
