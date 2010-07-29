--- setupext.py.orig    2010-07-28 11:18:08.000000000 -0400
+++ setupext.py 2010-07-28 11:21:02.000000000 -0400
@@ -68,6 +68,9 @@
     'freebsd4' : ['/usr/local', '/usr'],
     'freebsd5' : ['/usr/local', '/usr'],
     'freebsd6' : ['/usr/local', '/usr'],
+    'freebsd7' : ['/usr/local', '/usr'],
+    'freebsd8' : ['/usr/local', '/usr'],
+    'freebsd9' : ['/usr/local', '/usr'],
     'sunos5' : [os.getenv('MPLIB_BASE') or '/usr/local',],
     'gnukfreebsd5' : ['/usr/local', '/usr'],
     'gnukfreebsd6' : ['/usr/local', '/usr'],
@@ -789,7 +792,7 @@
         module.libraries.extend(wxlibs)
         return

-    get_pkgconfig(module, '', flags='--cppflags --libs', pkg_config_exec='wx-config')
+    get_pkgconfig(module, '', flags='--cppflags --libs', pkg_config_exec=wxconfig)

 # Make sure you use the Tk version given by Tkinter.TkVersion
 # or else you'll build for a wrong version of the Tcl
@@ -1092,9 +1095,9 @@

         # Add final versions of directories and libraries to module lists
         tcl_lib, tcl_inc, tk_lib, tk_inc = result
-        module.include_dirs.extend([tcl_inc, tk_inc])
-        module.library_dirs.extend([tcl_lib, tk_lib])
-        module.libraries.extend(['tk' + tk_ver, 'tcl' + tk_ver])
+        module.include_dirs.extend(["%%TCL_INCLUDEDIR%%", "%%TK_INCLUDEDIR%%"])
+        module.library_dirs.extend(["%%TCL_LIBDIR%%", "%%TK_LIBDIR%%"])
+        module.libraries.extend(['tk' + "%%TK_VER%%", 'tcl' + "%%TCL_VER%%"])

     return message

