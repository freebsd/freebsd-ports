# pytest-cov and its dependencies are not compulsory
#
# Subject: [PATCH] Limit dependencies to major instead of minor (#5342
# From c46f55bd48dabc02f033d252f8c64e2011f37361 Mon Sep 17 00:00:00 2001
# From: Chris Withers <chris@withers.org>
# Date: Tue, 18 Feb 2020 14:58:27 +0000

--- setup.py.orig	2019-05-16 14:22:45 UTC
+++ setup.py
@@ -42,8 +42,8 @@ if sys.argv[-1] == 'publish':
 packages = ['requests']
 
 requires = [
-    'chardet>=3.0.2,<3.1.0',
-    'idna>=2.5,<2.9',
+    'chardet>=3.0.2,<4',
+    'idna>=2.5,<3',
     'urllib3>=1.21.1,<1.26,!=1.25.0,!=1.25.1',
     'certifi>=2017.4.17'
 
@@ -101,7 +101,7 @@ setup(
     cmdclass={'test': PyTest},
     tests_require=test_requirements,
     extras_require={
-        'security': ['pyOpenSSL >= 0.14', 'cryptography>=1.3.4', 'idna>=2.0.0'],
+        'security': ['pyOpenSSL >= 0.14', 'cryptography>=1.3.4'],
         'socks': ['PySocks>=1.5.6, !=1.5.7'],
         'socks:sys_platform == "win32" and python_version == "2.7"': ['win_inet_pton'],
     },
