--- numpy/f2py/f2py2e.py.orig	2019-01-31 02:31:08 UTC
+++ numpy/f2py/f2py2e.py
@@ -599,6 +599,7 @@ def run_compile():
     include_dirs, sources = filter_files('-I', '', sources, remove_prefix=1)
     library_dirs, sources = filter_files('-L', '', sources, remove_prefix=1)
     libraries, sources = filter_files('-l', '', sources, remove_prefix=1)
+    extra_link_args, sources = filter_files('-Wl,|-B|-f','',sources,remove_prefix=0)
     undef_macros, sources = filter_files('-U', '', sources, remove_prefix=1)
     define_macros, sources = filter_files('-D', '', sources, remove_prefix=1)
     for i in range(len(define_macros)):
@@ -625,6 +626,7 @@ def run_compile():
                 'undef_macros': undef_macros,
                 'extra_objects': extra_objects,
                 'f2py_options': f2py_flags,
+                'extra_link_args': extra_link_args,
                 }
 
     if sysinfo_flags:
