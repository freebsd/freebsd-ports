--- SABnzbd.py.orig	2016-06-04 11:45:01 UTC
+++ SABnzbd.py
@@ -51,6 +51,9 @@ except:
     print "The Python module Cheetah is required"
     sys.exit(1)
 
+# Force python to load the patched version of cherrypy included with the port,
+# instead of any version that may be installed otherwise.
+sys.path.insert(0,%%DATADIR%%)
 import cherrypy
 if [int(n) for n in cherrypy.__version__.split('.')] < [3, 8, 0]:
     print 'Sorry, requires Python module Cherrypy 3.8.0+ (use the included version)'
@@ -1006,7 +1009,7 @@ def main():
             
     sabnzbd.MY_FULLNAME = os.path.normpath(os.path.abspath(sabnzbd.MY_FULLNAME))
     sabnzbd.MY_NAME = os.path.basename(sabnzbd.MY_FULLNAME)
-    sabnzbd.DIR_PROG = os.path.dirname(sabnzbd.MY_FULLNAME)
+    sabnzbd.DIR_PROG = %%DATADIR%%
     sabnzbd.DIR_INTERFACES = real_path(sabnzbd.DIR_PROG, DEF_INTERFACES)
     sabnzbd.DIR_LANGUAGE = real_path(sabnzbd.DIR_PROG, DEF_LANGUAGE)
     org_dir = os.getcwd()
