--- setup.py.orig	2017-11-25 07:11:10 UTC
+++ setup.py
@@ -174,10 +174,10 @@ def configure_dl(ext, config_cmd):
     log.info("checking for dlopen() availability ...")
     ok = config_cmd.check_header('dlfcn.h')
     if ok : ext.define_macros += [('HAVE_DLFCN_H', 1)]
-    ok = config_cmd.check_library('dl')
-    if ok: ext.libraries += ['dl']
+    #ok = config_cmd.check_library('dl')
+    #if ok: ext.libraries += ['dl']
     ok = config_cmd.check_function('dlopen',
-                                   libraries=['dl'],
+                                   #libraries=['dl'],
                                    decl=1, call=1)
     if ok: ext.define_macros += [('HAVE_DLOPEN', 1)]
 
@@ -287,7 +287,7 @@ def configure_libvt(lib, config_cmd):
         log_lib = 'vt.ompi'
     else:
         log_lib = 'vt.mpi'
-    dep_libs = ('dl', 'z', 'otf',)
+    dep_libs = ('z', 'otf',)
     ok = config_cmd.check_library(log_lib, lib.library_dirs)
     if not ok: return
     libraries = []
