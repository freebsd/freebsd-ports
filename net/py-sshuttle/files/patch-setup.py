--- setup.py.orig	2016-10-10 04:57:26 UTC
+++ setup.py
@@ -36,7 +36,7 @@ setup(
         'write_to': "sshuttle/version.py",
         'version_scheme': version_scheme,
     },
-    setup_requires=['setuptools_scm', 'pytest-runner'],
+    setup_requires=['setuptools_scm'],
     # version=version,
     url='https://github.com/sshuttle/sshuttle',
     author='Brian May',
@@ -61,6 +61,6 @@ setup(
             'sshuttle = sshuttle.cmdline:main',
         ],
     },
-    tests_require=['pytest', 'mock'],
+    tests_require=['pytest', 'pytest-runner', 'mock'],
     keywords="ssh vpn",
 )
