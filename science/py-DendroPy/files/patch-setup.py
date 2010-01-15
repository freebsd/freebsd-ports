--- setup.py.orig	2010-01-15 12:55:37.000000000 +0800
+++ setup.py	2010-01-15 12:55:53.000000000 +0800
@@ -31,13 +31,6 @@
 # setuptools/distutils/etc. import and configuration
 
 try:
-    import ez_setup
-    try:
-        ez_setup_path = " ('" + os.path.abspath(ez_setup.__file__) + "')"
-    except OSError:
-        ez_setup_path = ""
-    sys.stderr.write("using ez_setup%s\n" %  ez_setup_path)
-    ez_setup.use_setuptools()
     import setuptools
     try:
         setuptools_path = " ('" +  os.path.abspath(setuptools.__file__) + "')"
