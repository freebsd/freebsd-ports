* Prevent installation of the "tests" folder containing the test suite into
  the top-directory.

* Remove "testdata" directory from installation. It is only required for the
  testsuite.

--- setup.py.orig	2026-11-10 07:42:13 UTC
+++ setup.py
@@ -54,8 +54,6 @@ setup(
         'Programming Language :: Python :: 3',
         'Topic :: Software Development :: Libraries',
     ],
-    packages=find_packages(),
+    packages=find_packages(exclude=['tests']),
     entry_points={'console_scripts': ['textfsm=textfsm.parser:main']},
-    include_package_data=True,
-    package_data={'textfsm': ['../testdata/*']},
 )
