Remove "testdata" directory from installation. It is only required for the
testsuite.

--- setup.py.orig	2025-03-21 04:48:22 UTC
+++ setup.py
@@ -50,6 +50,4 @@ setup(
     ],
     packages=['textfsm'],
     entry_points={'console_scripts': ['textfsm=textfsm.parser:main']},
-    include_package_data=True,
-    package_data={'textfsm': ['../testdata/*']},
 )
