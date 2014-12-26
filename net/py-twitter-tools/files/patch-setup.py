--- setup.py.orig	2014-12-26 02:42:01 UTC
+++ setup.py
@@ -9,6 +9,10 @@ install_requires = [
 if sys.version_info < (2,7):
     install_requires.append('argparse')
 
+tests_require = [
+    'nose',
+]
+
 setup(name='twitter',
       version=version,
       description="An API and command-line toolset for Twitter (twitter.com)",
@@ -39,6 +43,8 @@ setup(name='twitter',
       include_package_data=True,
       zip_safe=True,
       install_requires=install_requires,
+      tests_require=tests_require,
+      test_suite = 'nose.collector',
       entry_points="""
       # -*- Entry points: -*-
       [console_scripts]
