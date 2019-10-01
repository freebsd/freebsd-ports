--- setup.py.orig	2015-09-16 19:40:15 UTC
+++ setup.py
@@ -11,8 +11,8 @@ from DenyHosts.util import normalize_whi
 from DenyHosts.version import VERSION
 
 etcpath = "/etc"
-manpath = "/usr/share/man/man8"
-libpath = "/usr/share/denyhosts"
+manpath = "%%PREFIX%%/man/man8"
+libpath = "%%PREFIX%%/share/denyhosts"
 scriptspath = ospj("scripts", libpath)
 pluginspath = ospj("plugins", libpath)
 
@@ -28,7 +28,6 @@ setup(
     packages=["DenyHosts"],
     requires=["ipaddr"],
     data_files=[
-        (etcpath, glob("denyhosts.conf")),
         (manpath, glob("denyhosts.8")),
     ],
     license="GPL v2",
