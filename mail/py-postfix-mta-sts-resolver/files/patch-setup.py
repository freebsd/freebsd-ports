--- setup.py.orig	2020-01-11 21:21:32 UTC
+++ setup.py
@@ -23,7 +23,6 @@ setup(name='postfix_mta_sts_resolver',
           'aiodns>=1.1.1',
           'aiohttp>=3.4.4',
           'PyYAML>=3.12',
-          'sdnotify>=0.3.2',
       ],
       extras_require={
           'sqlite': 'aiosqlite>=0.10.0',
