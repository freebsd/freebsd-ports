
$FreeBSD$

--- setup.py.orig
+++ setup.py
@@ -8,7 +8,7 @@
 from glob import glob
 
 
-libpath = "/usr/share/denyhosts"
+libpath = "%%PREFIX%%/share/denyhosts"
 scriptspath = "%s/scripts" % libpath
 pluginspath = "%s/plugins" % libpath
 
@@ -26,11 +26,8 @@
       data_files=[(libpath, glob("denyhosts.cfg-dist")),
                   (libpath, glob("setup.py")),
                   (libpath, glob("daemon-control-dist")),
-                  (libpath, glob("CHANGELOG.txt")),
-                  (libpath, glob("README.txt")),
                   (scriptspath, glob("scripts/*")),
-                  (pluginspath, glob("plugins/*")),
-                  (libpath, glob("LICENSE.txt"))],
+                  (pluginspath, glob("plugins/*"))],
       license="GPL v2",
       ##extra_path='denyhosts',
       long_description="""
