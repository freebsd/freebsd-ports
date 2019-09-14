This was part of a pull request that has been merged upstream. Most likely
this patch can be removed on the next release of python-fido2.

See https://github.com/Yubico/python-fido2/pull/64 and
https://github.com/Yubico/python-fido2/commit/19c86d5459931b8a76d1adc76420a8a1e0c0cf2e

--- setup.py.orig	2019-06-17 10:59:34 UTC
+++ setup.py
@@ -48,13 +48,14 @@ setup(
     install_requires=[
         'six',
         'cryptography>=1.5',
+        'uhid-freebsd>=1.2.1;platform_system=="FreeBSD"',
     ],
     extras_require={
         ':python_version < "3.4"': ['enum34'],
         'pcsc': ['pyscard']
     },
     test_suite='test',
-    tests_require=['mock>=1.0.1', 'pyfakefs>=3.4'],
+    tests_require=['mock>=1.0.1', 'pyfakefs>=3.4;platform_system=="Linux"'],
     classifiers=[
         'License :: OSI Approved :: BSD License',
         'License :: OSI Approved :: Apache Software License',
