--- platform/python/virtualenv/site.py.orig	2021-02-05 18:43:01 UTC
+++ platform/python/virtualenv/site.py
@@ -233,10 +233,10 @@ def addsitepackages(known_paths, sys_prefix=sys.prefix
             elif os.sep == '/':
                 sitedirs = [os.path.join(prefix,
                                          "lib",
-                                         "python" + sys.version[:3],
+                                         "tauthon" + sys.version[:3],
                                          "site-packages"),
                             os.path.join(prefix, "lib", "site-python"),
-                            os.path.join(prefix, "python" + sys.version[:3], "lib-dynload")]
+                            os.path.join(prefix, "tauthon" + sys.version[:3], "lib-dynload")]
                 lib64_dir = os.path.join(prefix, "lib64", "python" + sys.version[:3], "site-packages")
                 if (os.path.exists(lib64_dir) and
                     os.path.realpath(lib64_dir) not in [os.path.realpath(p) for p in sitedirs]):
@@ -583,7 +583,7 @@ def virtual_install_main_packages():
     elif sys.platform == 'win32' and os.sep == '\\':
         paths = [os.path.join(sys.real_prefix, 'Lib'), os.path.join(sys.real_prefix, 'DLLs')]
     else:
-        paths = [os.path.join(sys.real_prefix, 'lib', 'python'+sys.version[:3])]
+        paths = [os.path.join(sys.real_prefix, 'lib', 'tauthon'+sys.version[:3])]
         hardcoded_relative_dirs = paths[:] # for the special 'darwin' case below
         lib64_path = os.path.join(sys.real_prefix, 'lib64', 'python'+sys.version[:3])
         if os.path.exists(lib64_path):
@@ -602,7 +602,7 @@ def virtual_install_main_packages():
             # This is a non-multiarch aware Python.  Fallback to the old way.
             arch = sys.platform
         plat_path = os.path.join(sys.real_prefix, 'lib',
-                                 'python'+sys.version[:3],
+                                 'tauthon'+sys.version[:3],
                                  'plat-%s' % arch)
         if os.path.exists(plat_path):
             paths.append(plat_path)
