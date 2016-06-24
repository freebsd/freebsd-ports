--- supervisor/options.py.orig	2016-06-08 17:09:41.213297000 +0300
+++ supervisor/options.py	2016-06-08 17:10:18.970354000 +0300
@@ -96,13 +96,7 @@ class Options:
         self.add("configfile", None, "c:", "configuration=")
 
         here = os.path.dirname(os.path.dirname(sys.argv[0]))
-        searchpaths = [os.path.join(here, 'etc', 'supervisord.conf'),
-                       os.path.join(here, 'supervisord.conf'),
-                       'supervisord.conf',
-                       'etc/supervisord.conf',
-                       '/etc/supervisord.conf',
-                       '/etc/supervisor/supervisord.conf',
-                       ]
+        searchpaths = [ '%%PREFIX%%/etc/supervisord.conf' ]
         self.searchpaths = searchpaths
 
         self.environ_expansions = {}
