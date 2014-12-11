--- numpy/f2py/f2py2e.py.orig	2014-10-26 10:36:14.000000000 -0400
+++ numpy/f2py/f2py2e.py	2014-12-11 07:52:11.000000000 -0500
@@ -516,6 +516,7 @@
     include_dirs, sources = filter_files('-I', '', sources, remove_prefix=1)
     library_dirs, sources = filter_files('-L', '', sources, remove_prefix=1)
     libraries, sources = filter_files('-l', '', sources, remove_prefix=1)
+    extra_link_args, sources = filter_files('-Wl,|-B|-f','',sources,remove_prefix=0)
     undef_macros, sources = filter_files('-U', '', sources, remove_prefix=1)
     define_macros, sources = filter_files('-D', '', sources, remove_prefix=1)
     using_numarray = 0
@@ -551,6 +552,7 @@
                 'undef_macros': undef_macros,
                 'extra_objects': extra_objects,
                 'f2py_options': f2py_flags,
+                'extra_link_args': extra_link_args,
                 }
 
     if sysinfo_flags:
