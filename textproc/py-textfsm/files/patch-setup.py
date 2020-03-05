Remove "testdata" directory from installation. It is only required for the
testsuite.

--- setup.py.orig	2019-11-26 11:17:07 UTC
+++ setup.py
@@ -52,7 +52,6 @@ setup(name='textfsm',
         ]
       },      
       include_package_data=True,
-      package_data={'textfsm': ['../testdata/*']},
       install_requires=['six', 'future'],
       setup_requires=['pytest-runner'],
       tests_require=['pytest'])
