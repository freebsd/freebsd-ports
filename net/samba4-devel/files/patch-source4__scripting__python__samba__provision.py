--- ./source4/scripting/python/samba/provision.py.orig	2010-01-11 05:35:28.000000000 +0000
+++ ./source4/scripting/python/samba/provision.py	2010-01-24 21:49:26.000000000 +0000
@@ -64,7 +64,7 @@
     dirname = os.path.dirname(__file__)
     if "/site-packages/" in dirname:
         prefix = "/".join(dirname[:dirname.index("/site-packages/")].split("/")[:-2])
-        for suffix in ["share/setup", "share/samba/setup", "setup"]:
+        for suffix in ["share/setup", "share/samba4/setup", "setup"]:
             ret = os.path.join(prefix, suffix)
             if os.path.isdir(ret):
                 return ret
