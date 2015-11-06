--- setup.py.orig	2015-11-04 07:35:05 UTC
+++ setup.py
@@ -118,8 +118,6 @@ setup(
         'docs': docs_extras,
         'testing': testing_extras,
     },
-
-    tests_require=install_requires,
     # to test all packages run "python setup.py test -s
     # {acme,letsencrypt_apache,letsencrypt_nginx}"
     test_suite='letsencrypt',
