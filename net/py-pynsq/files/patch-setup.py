--- ./setup.py.orig	2013-06-08 23:24:54.875536114 +1000
+++ ./setup.py	2013-06-08 23:25:23.966041820 +1000
@@ -1,17 +1,38 @@
 from setuptools import setup
+from setuptools.command.test import test as TestCommand
+import sys
+
+
+class PyTest(TestCommand):
+    def finalize_options(self):
+        TestCommand.finalize_options(self)
+        self.test_args = []
+        self.test_suite = True
+    def run_tests(self):
+        import pytest
+        errno = pytest.main(self.test_args)
+        sys.exit(errno)
+
 
+# also update in nsq/__init__.py
 version = '0.4.2'
 
-setup(name='pynsq',
-      version=version,
-      description="a Python module for NSQ",
-      keywords='python nsq',
-      author='Matt Reiferson',
-      author_email='snakes@gmail.com',
-      url='http://github.com/bitly/pynsq',
-      download_url='https://s3.amazonaws.com/bitly-downloads/nsq/pynsq-%s.tar.gz' % version,
-      packages=['nsq'],
-      requires=['tornado'],
-      include_package_data=True,
-      zip_safe=True,
-      )
+
+setup(
+    name='pynsq',
+    version=version,
+    description="a Python module for NSQ",
+    keywords='python nsq',
+    author='Matt Reiferson',
+    author_email='snakes@gmail.com',
+    url='http://github.com/bitly/pynsq',
+    download_url='https://s3.amazonaws.com/bitly-downloads/nsq/pynsq-%s.tar.gz' % version,
+    packages=['nsq'],
+    requires=['tornado'],
+    include_package_data=True,
+    zip_safe=False,
+    tests_require=['pytest', 'mock', 'tornado'],
+    cmdclass={'test': PyTest},
+)
+
+
