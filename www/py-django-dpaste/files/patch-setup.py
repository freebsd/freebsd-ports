--- setup.py.orig	2016-08-15 03:37:55 UTC
+++ setup.py
@@ -4,19 +4,6 @@ from sys import exit
 from setuptools import find_packages, setup
 from setuptools.command.test import test as TestCommand
 
-
-class Tox(TestCommand):
-    def finalize_options(self):
-        TestCommand.finalize_options(self)
-        self.test_args = []
-        self.test_suite = True
-
-    def run_tests(self):
-        #import here, cause outside the eggs aren't loaded
-        import tox
-        errno = tox.cmdline(self.test_args)
-        exit(errno)
-
 long_description = u'\n\n'.join((
     open('README.rst').read(),
     open('CHANGELOG').read()
@@ -54,10 +41,5 @@ setup(
         'pygments>=1.6',
         'requests>=2.0.0',
     ],
-    tests_require=[
-        'tox>=1.6.1'
-    ],
-    cmdclass={
-        'test': Tox
-    },
+    test_suite='runtests.runtests',
 )
