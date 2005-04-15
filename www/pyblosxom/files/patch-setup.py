--- setup.py.orig	Sun Mar 27 00:05:18 2005
+++ setup.py	Wed Apr 13 17:17:06 2005
@@ -64,7 +64,7 @@
 
     # we want to move the web script files as well, so we sneak them
     # in here.
-    pydf.append( [os.path.join('share', PVER, 'web'),
+    pydf.append( [os.path.join('share/examples', PVER),
                   [os.path.normpath("web/pyblosxom.cgi"), 
                    os.path.normpath("web/pyblosxom.tac"), 
                    os.path.normpath("web/pyblosxom_wsgi.cgi"), 
