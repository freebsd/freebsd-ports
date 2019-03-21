--- setup.py.orig	2019-03-01 20:19:03 UTC
+++ setup.py
@@ -19,6 +19,9 @@ requires = [
     's3transfer>=0.2.0,<0.3.0'
 ]
 
+tests_require = [
+    'nose',
+]
 
 def get_version():
     init = open(os.path.join(ROOT, 'boto3', '__init__.py')).read()
@@ -42,6 +45,8 @@ setup(
     },
     include_package_data=True,
     install_requires=requires,
+    tests_require=tests_require,
+    test_suite='nose.collector',
     license="Apache License 2.0",
     classifiers=[
         'Development Status :: 5 - Production/Stable',
