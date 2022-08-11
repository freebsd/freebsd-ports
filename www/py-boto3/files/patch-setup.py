--- setup.py.orig	2021-10-13 18:09:14 UTC
+++ setup.py
@@ -14,10 +14,13 @@ VERSION_RE = re.compile(r'''__version__ = ['"]([0-9.]+
 
 requires = [
     'botocore>=1.21.61,<1.22.0',
-    'jmespath>=0.7.1,<1.0.0',
+    'jmespath>=0.7.1,<2.0.0',
     's3transfer>=0.5.0,<0.6.0'
 ]
 
+tests_require = [
+    'nose',
+]
 
 def get_version():
     init = open(os.path.join(ROOT, 'boto3', '__init__.py')).read()
@@ -41,6 +44,8 @@ setup(
     },
     include_package_data=True,
     install_requires=requires,
+    tests_require=tests_require,
+    test_suite='nose.collector',
     license="Apache License 2.0",
     python_requires=">= 3.6",
     classifiers=[
