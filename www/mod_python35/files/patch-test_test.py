--- test/test.py.orig	2013-11-12 03:21:34 UTC
+++ test/test.py
@@ -310,6 +310,12 @@ class HttpdCtrl:
         modpath = LIBEXECDIR
 
         s = Container(
+            IfModule("!prefork.c",
+            IfModule("!worker.c",
+            IfModule("!perchild.c",
+            IfModule("!mpm_winnt.c",
+                     LoadModule("mpm_prefork_module %%APACHEMODDIR%%/mod_mpm_prefork.so"),
+            )))),
             IfModule("prefork.c",
                      StartServers("3"),
                      MaxSpareServers("1")),
