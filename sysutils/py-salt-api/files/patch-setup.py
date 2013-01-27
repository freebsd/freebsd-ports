--- setup.py	2013-01-22 09:29:51.251688608 -0700
+++ setup.py-new	2013-01-22 09:35:20.608700323 -0700
@@ -43,9 +43,9 @@
         ],
     package_data={
         'saltapi.netapi.rest_cherrypy': ['tmpl/*']},
-    data_files=[('share/man/man1',
+    data_files=[('man/man1',
         ['doc/man/salt-api.1']),
-        ('share/man/man7',
+        ('man/man7',
         ['doc/man/salt-api.7'])],
     scripts=['scripts/salt-api'],
     test_suite='unittest2.collector' if 'unittest2' in locals() else None)
