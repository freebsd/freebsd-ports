--- setup.py.orig	2021-05-15 19:43:51 UTC
+++ setup.py
@@ -579,13 +579,6 @@ if sys.version_info >= (2, 5):
 # -----------------------------------------------------------------------------
 
 if sys.version_info >= (3,):
-    # Integrate the py2to3 step into our build.
-    if using_setuptools:
-        extra_setup_params["use_2to3"] = True
-    else:
-        from distutils.command.build_py import build_py_2to3
-        distutils_cmdclass["build_py"] = build_py_2to3
-
     # Teach Python's urllib lib2to3 fixer that the old urllib2.__version__ data
     # member is now stored in the urllib.request module.
     import lib2to3.fixes.fix_urllib
