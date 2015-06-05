--- setup.py.orig	2015-06-05 04:36:25 UTC
+++ setup.py
@@ -27,6 +27,7 @@ packages = [
 ]
 
 requires = []
+tests_require = ['pytest']
 
 version = ''
 with open('requests/__init__.py', 'r') as fd:
@@ -54,6 +55,8 @@ setup(
     package_dir={'requests': 'requests'},
     include_package_data=True,
     install_requires=requires,
+    tests_require=tests_require,
+    test_suite='test_requests',
     license='Apache 2.0',
     zip_safe=False,
     classifiers=(
