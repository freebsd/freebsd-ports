--- supervisor/options.py.orig	2018-02-15 21:18:33 UTC
+++ supervisor/options.py
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
