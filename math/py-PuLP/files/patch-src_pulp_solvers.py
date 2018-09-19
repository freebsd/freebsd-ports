--- src/pulp/solvers.py.orig	2017-07-16 22:25:50 UTC
+++ src/pulp/solvers.py
@@ -135,6 +135,9 @@ elif sys.platform in ['darwin']:
     operating_system = "osx"
     arch = '64'
     PULPCFGFILE += ".osx"
+elif sys.platform in ['freebsd']:
+    operating_system = "freebsd"
+    PULPCFGFILE += ".freebsd"
 else:
     operating_system = "linux"
     PULPCFGFILE += ".linux"
