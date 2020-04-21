--- buildtools/wafsamba/samba_autoconf.py.orig	2019-08-20 15:35:08 UTC
+++ buildtools/wafsamba/samba_autoconf.py
@@ -573,7 +573,7 @@ def library_flags(self, libs):
 
 
 @conf
-def CHECK_LIB(conf, libs, mandatory=False, empty_decl=True, set_target=True, shlib=False):
+def CHECK_LIB(conf, libs, mandatory=False, empty_decl=True, set_target=True, shlib=False, msg=None):
     '''check if a set of libraries exist as system libraries
 
     returns the sublist of libs that do exist as a syslib or []
@@ -593,11 +593,14 @@ int foo()
             ret.append(lib)
             continue
 
+        if msg is None:
+            msg = 'Checking for library %s' % lib
+
         (ccflags, ldflags, cpppath) = library_flags(conf, lib)
         if shlib:
-            res = conf.check(features='c cshlib', fragment=fragment, lib=lib, uselib_store=lib, cflags=ccflags, ldflags=ldflags, uselib=lib.upper(), mandatory=False)
+            res = conf.check(features='c cshlib', fragment=fragment, lib=lib, uselib_store=lib, cflags=ccflags, ldflags=ldflags, uselib=lib.upper(), mandatory=False, msg=msg)
         else:
-            res = conf.check(lib=lib, uselib_store=lib, cflags=ccflags, ldflags=ldflags, uselib=lib.upper(), mandatory=False)
+            res = conf.check(lib=lib, uselib_store=lib, cflags=ccflags, ldflags=ldflags, uselib=lib.upper(), mandatory=False, msg=msg)
 
         if not res:
             if mandatory:
@@ -949,5 +952,5 @@ def SAMBA_CHECK_UNDEFINED_SYMBOL_FLAGS(c
         conf.env.undefined_ldflags = conf.ADD_LDFLAGS('-Wl,-no-undefined', testflags=True)
 
         if (conf.env.undefined_ignore_ldflags == [] and
-            conf.CHECK_LDFLAGS(['-undefined', 'dynamic_lookup'])):
+            conf.CHECK_LDFLAGS(['-undefined', 'dynamic_lookup'] + conf.env.WERROR_CFLAGS)):
             conf.env.undefined_ignore_ldflags = ['-undefined', 'dynamic_lookup']
