--- SABnzbd.py.orig	2011-12-14 11:47:28.584883016 -0500
+++ SABnzbd.py	2011-12-14 11:49:08.861713731 -0500
@@ -40,6 +40,9 @@
     print "The Python module Cheetah is required"
     sys.exit(1)
 
+# Force python to load the patched version of cherrypy included with the port,
+# instead of any version that may be installed otherwise.
+sys.path.insert(0,%%PREFIX%%)
 import cherrypy
 if not cherrypy.__version__.startswith("3.2"):
     print "Sorry, requires Python module Cherrypy 3.2 (use the included version)"
@@ -962,7 +965,7 @@
 
     sabnzbd.MY_FULLNAME = os.path.normpath(os.path.abspath(sabnzbd.MY_FULLNAME))
     sabnzbd.MY_NAME = os.path.basename(sabnzbd.MY_FULLNAME)
-    sabnzbd.DIR_PROG = os.path.dirname(sabnzbd.MY_FULLNAME)
+    sabnzbd.DIR_PROG = %%PREFIX%%
     sabnzbd.DIR_INTERFACES = real_path(sabnzbd.DIR_PROG, DEF_INTERFACES)
     sabnzbd.DIR_LANGUAGE = real_path(sabnzbd.DIR_PROG, DEF_LANGUAGE)
     org_dir = os.getcwd()
