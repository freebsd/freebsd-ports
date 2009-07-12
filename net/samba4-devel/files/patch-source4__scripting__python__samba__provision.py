--- ./source4/scripting/python/samba/provision.py.orig	2009-06-19 04:36:48.000000000 +0000
+++ ./source4/scripting/python/samba/provision.py	2009-07-12 02:39:36.000000000 +0000
@@ -54,7 +54,7 @@
     dirname = os.path.dirname(__file__)
     if "/site-packages/" in dirname:
         prefix = "/".join(dirname[:dirname.index("/site-packages/")].split("/")[:-2])
-        for suffix in ["share/setup", "share/samba/setup", "setup"]:
+        for suffix in ["share/setup", "share/samba4/setup", "setup"]:
             ret = os.path.join(prefix, suffix)
             if os.path.isdir(ret):
                 return ret
