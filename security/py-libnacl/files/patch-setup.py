--- setup.py.orig	2016-01-04 16:47:15 UTC
+++ setup.py
@@ -29,4 +29,6 @@ setup(name=NAME,
           'Intended Audience :: Developers',
           'Topic :: Security :: Cryptography',
           ],
-      packages=['libnacl'])
+      packages=['libnacl'],
+      test_suite='tests.runtests.run_suite',
+)
