--- setupext.py.orig	2008-08-03 13:15:22.000000000 -0500
+++ setupext.py	2008-09-29 13:20:02.000000000 -0500
@@ -55,6 +55,8 @@
     'freebsd4' : ['/usr/local', '/usr'],
     'freebsd5' : ['/usr/local', '/usr'],
     'freebsd6' : ['/usr/local', '/usr'],
+    'freebsd7' : ['/usr/local', '/usr'],
+    'freebsd8' : ['/usr/local', '/usr'],
     'sunos5' : [os.getenv('MPLIB_BASE') or '/usr/local',],
     'gnukfreebsd5' : ['/usr/local', '/usr'],
     'gnukfreebsd6' : ['/usr/local', '/usr'],
@@ -814,7 +816,7 @@
         module.libraries.extend(wxlibs)
         return
 
-    get_pkgconfig(module, '', flags='--cppflags --libs', pkg_config_exec='wx-config')
+    get_pkgconfig(module, '', flags='--cppflags --libs', pkg_config_exec=wxconfig)
 
 # Make sure you use the Tk version given by Tkinter.TkVersion
 # or else you'll build for a wrong version of the Tcl
@@ -1096,9 +1098,9 @@
 
         # Add final versions of directories and libraries to module lists
         tcl_lib, tcl_inc, tk_lib, tk_inc = result
-        module.include_dirs.extend([tcl_inc, tk_inc])
-        module.library_dirs.extend([tcl_lib, tk_lib])
-        module.libraries.extend(['tk' + tk_ver, 'tcl' + tk_ver])
+        module.include_dirs.extend(["/usr/local/include/tcl8.5", "/usr/local/include/tk8.5"])
+        module.library_dirs.extend(["%%TCL_LIBDIR%%", "%%TK_LIBDIR%%"])
+        module.libraries.extend(['tk85', 'tcl85'])
 
     return message
 
