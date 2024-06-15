--- numpy/f2py/f2py2e.py.orig	2024-06-12 01:22:27 UTC
+++ numpy/f2py/f2py2e.py
@@ -693,6 +693,7 @@ def run_compile():
     extra_objects, sources = filter_files('', '[.](o|a|so|dylib)', sources)
     library_dirs, sources = filter_files('-L', '', sources, remove_prefix=1)
     libraries, sources = filter_files('-l', '', sources, remove_prefix=1)
+    extra_link_args, sources = filter_files('-Wl,|-B|-f','',sources,remove_prefix=0)
     undef_macros, sources = filter_files('-U', '', sources, remove_prefix=1)
     define_macros, sources = filter_files('-D', '', sources, remove_prefix=1)
     for i in range(len(define_macros)):
@@ -727,6 +728,7 @@ def run_compile():
         define_macros,
         undef_macros,
         f2py_flags,
+	extra_link_args,
         sysinfo_flags,
         fc_flags,
         flib_flags,
