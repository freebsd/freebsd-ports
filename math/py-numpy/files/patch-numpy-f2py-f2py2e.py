--- numpy/f2py/f2py2e.py.orig	2012-01-25 06:59:14.651304791 -0600
+++ numpy/f2py/f2py2e.py	2012-01-25 07:00:58.475075133 -0600
@@ -514,6 +514,7 @@
     include_dirs, sources = filter_files('-I','',sources,remove_prefix=1)
     library_dirs, sources = filter_files('-L','',sources,remove_prefix=1)
     libraries, sources = filter_files('-l','',sources,remove_prefix=1)
+    extra_link_args, sources = filter_files('-Wl,','',sources,remove_prefix=0)
     undef_macros, sources = filter_files('-U','',sources,remove_prefix=1)
     define_macros, sources = filter_files('-D','',sources,remove_prefix=1)
     using_numarray = 0
@@ -549,6 +550,7 @@
                 'undef_macros': undef_macros,
                 'extra_objects': extra_objects,
                 'f2py_options': f2py_flags,
+                'extra_link_args': extra_link_args,
                 }
 
     if sysinfo_flags:
