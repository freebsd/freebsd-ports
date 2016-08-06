--- setup.py.orig	2016-08-03 00:15:58 UTC
+++ setup.py
@@ -15,11 +15,14 @@ VERSION_RE = re.compile(r'''__version__ 
 
 
 requires = [
-    'botocore>=1.4.1,<1.5.0',
-    'jmespath>=0.7.1,<1.0.0',
-    's3transfer>=0.1.0,<0.2.0'
+    'botocore>=1.4.1',
+    'jmespath>=0.7.1',
+    's3transfer>=0.1.0'
 ]
 
+tests_require = [
+    'nose',
+]
 
 def get_version():
     init = open(os.path.join(ROOT, 'boto3', '__init__.py')).read()
@@ -43,6 +46,8 @@ setup(
     },
     include_package_data=True,
     install_requires=requires,
+    tests_require=tests_require,
+    test_suite='nose.collector',
     license="Apache License 2.0",
     classifiers=[
         'Development Status :: 5 - Production/Stable',
