--- Hercules/globals.py.orig	2006-09-03 11:40:34.000000000 +0400
+++ Hercules/globals.py	2011-09-29 11:54:03.000000000 +0400
@@ -63,7 +63,7 @@
         dir = os.path.abspath(os.path.dirname(sys.argv[0]))
         sharedir = '%s' % dir
     elif os.name == 'posix':
-        sharedir = '/usr/share/hercules'
+        sharedir = '%%PREFIX%%/share/hercules/'
 else:
     sharedir = ''
 debug("Using share directory: %s" % sharedir)
