--- supervisor/options.py.orig	2013-06-20 21:00:12.000000000 +0400
+++ supervisor/options.py	2013-08-08 14:41:08.000000000 +0400
@@ -99,10 +99,7 @@
         self.add("configfile", None, "c:", "configuration=")
 
         here = os.path.dirname(os.path.dirname(sys.argv[0]))
-        searchpaths = [os.path.join(here, 'etc', 'supervisord.conf'),
-                       os.path.join(here, 'supervisord.conf'),
-                       'supervisord.conf', 'etc/supervisord.conf',
-                       '/etc/supervisord.conf']
+        searchpaths = [ '/usr/local/etc/supervisord.conf' ]
         self.searchpaths = searchpaths
 
     def default_configfile(self):
