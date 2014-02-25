--- ./setup.py.orig	2014-02-23 08:35:18.000000000 +1100
+++ ./setup.py	2014-02-24 19:34:58.741325597 +1100
@@ -14,7 +14,8 @@
 from distutils.command.build import build
 
 from setuptools import setup, find_packages
-
+from setuptools.command.test import test as TestCommand
+import sys
 
 base_dir = os.path.dirname(__file__)
 
@@ -31,6 +32,12 @@
     SIX_DEPENDENCY
 ]
 
+test_requirements = [
+	"pytest",
+	"pretend",
+	"iso8601"
+]
+
 
 class cffi_build(build):
     """
@@ -63,6 +70,16 @@
 
         build.finalize_options(self)
 
+class PyTest(TestCommand):
+    def finalize_options(self):
+        TestCommand.finalize_options(self)
+        self.test_args = []
+        self.test_suite = True
+    def run_tests(self):
+        #import here, cause outside the eggs aren't loaded
+        import pytest
+        errno = pytest.main(self.test_args)
+        sys.exit(errno)
 
 with open(os.path.join(base_dir, "README.rst")) as f:
     long_description = f.read()
@@ -105,11 +122,12 @@
 
     install_requires=requirements,
     setup_requires=requirements,
-
+    tests_require=test_requirements,
     # for cffi
     zip_safe=False,
     ext_package="cryptography",
     cmdclass={
         "build": cffi_build,
+	"test": PyTest,
     }
 )
