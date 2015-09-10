--- setup.py.orig	2015-03-17 16:11:06 UTC
+++ setup.py
@@ -36,4 +36,6 @@ setup(name=NAME,
           'Intended Audience :: Developers',
           'Topic :: Security :: Cryptography',
           ],
-      packages=['libnacl'])
+      packages=['libnacl'],
+      test_suite='tests.runtests.run_suite',
+)
