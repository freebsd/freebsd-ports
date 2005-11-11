
$FreeBSD$

--- setup.py.orig
+++ setup.py
@@ -7,7 +7,7 @@
 from glob import glob
 
 
-libpath = "/usr/share/denyhosts"
+libpath = "%%PREFIX%%/share/denyhosts"
 
 #########################################################################
 
@@ -24,10 +24,7 @@
       data_files=[(libpath, glob("denyhosts.cfg-dist")),
                   (libpath, glob("denyhosts-daemon-initscript")),
                   (libpath, glob("setup.py")),
-                  (libpath, glob("daemon-control-dist")),
-                  (libpath, glob("CHANGELOG.txt")),
-                  (libpath, glob("README.txt")),
-                  (libpath, glob("LICENSE.txt"))],
+                  (libpath, glob("daemon-control-dist"))],
       license="GPL",
       ##extra_path='denyhosts',
       long_description="""
