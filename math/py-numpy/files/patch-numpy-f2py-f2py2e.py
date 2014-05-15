--- numpy/f2py/f2py2e.py.orig	2013-10-30 13:31:41.000000000 -0500
+++ numpy/f2py/f2py2e.py	2014-04-09 10:23:49.000000000 -0500
@@ -520,6 +520,7 @@
     include_dirs, sources = filter_files('-I', '', sources, remove_prefix=1)
     library_dirs, sources = filter_files('-L', '', sources, remove_prefix=1)
     libraries, sources = filter_files('-l', '', sources, remove_prefix=1)
+    extra_link_args, sources = filter_files('-Wl,|-B','',sources,remove_prefix=0)
     undef_macros, sources = filter_files('-U', '', sources, remove_prefix=1)
     define_macros, sources = filter_files('-D', '', sources, remove_prefix=1)
     using_numarray = 0
@@ -555,6 +556,7 @@
                 'undef_macros': undef_macros,
                 'extra_objects': extra_objects,
                 'f2py_options': f2py_flags,
+                'extra_link_args': extra_link_args,
                 }
 
     if sysinfo_flags:
