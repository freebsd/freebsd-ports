To be upstreamed: remove dependencies, not actually required to
use the library.

--- setup.py.orig	2016-07-22 12:01:01 UTC
+++ setup.py
@@ -129,7 +129,8 @@ class PreRelease(Command):
             raise RuntimeError(
                 "Current version of the package is equal or lower than the already published ones (PyPi). Increse version to be able to pass prerelease stage.")
 
-requires = ['autopep8', 'six', 'pep8', 'pytest-cov', 'pytest-pep8', 'setuptools', 'pytest', 'pytest-timeout']
+requires = ['six', 'setuptools']
+tests_requires = ['autopep8', 'six', 'pep8', 'pytest-cov', 'pytest-pep8', 'setuptools', 'pytest', 'pytest-timeout']
 
 setup(
     name=NAME,
@@ -137,8 +138,7 @@ setup(
     cmdclass={'test': PyTest, 'release': Release, 'prerelease': PreRelease},
     packages=find_packages(exclude=['tests']),
     include_package_data=True,
-    tests_require=requires,
-    setup_requires=requires,
+    tests_require=tests_requires,
     install_requires=requires,
 
     license='BSD',
