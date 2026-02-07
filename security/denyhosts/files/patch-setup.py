--- setup.py.orig	2020-05-08 14:20:42 UTC
+++ setup.py
@@ -13,8 +13,8 @@ etcpath = "/etc"
 from DenyHosts.version import VERSION
 
 etcpath = "/etc"
-manpath = "/usr/share/man/man8"
-libpath = "/usr/share/denyhosts"
+manpath = "%%PREFIX%%/share/man/man8"
+libpath = "%%PREFIX%%/share/denyhosts"
 scriptspath = ospj("scripts", libpath)
 pluginspath = ospj("plugins", libpath)
 denyhostsman = 'denyhosts.8'
@@ -40,7 +40,7 @@ setup(
         )
 
 setup(
-    name="DenyHosts",
+    name="denyhosts",
     version=VERSION,
     description="DenyHost is a utility to help sys admins thwart ssh hackers",
     author="Jesse Smith",
@@ -50,10 +50,6 @@ setup(
     package_dir={'DenyHosts': 'DenyHosts'},
     packages=["DenyHosts"],
     requires=["ipaddr"],
-    data_files=[
-        (etcpath, glob("denyhosts.conf")),
-        (manpath, glob(denyhostsman)),
-    ],
     license="GPL v2",
     long_description=normalize_whitespace(
         """
