--- setup.py.orig	2019-11-11 16:27:27 UTC
+++ setup.py
@@ -46,7 +46,6 @@ as LDAP.""",
         'nss_cache.update', 'nss_cache.sources'
     ],
     scripts=['nsscache'],
-    data_files=[('/etc', ['nsscache.conf'])],
     python_requires='~=3.4',
     setup_requires=['pytest-runner'],
     tests_require=['pytest', 'mox3', 'pytest-cov', 'python-coveralls'],
