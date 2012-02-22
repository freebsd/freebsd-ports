--- setup.py.orig	2011-04-03 22:20:03.000000000 -0400
+++ setup.py	2011-05-24 11:48:33.000000000 -0400
@@ -15,11 +15,11 @@
 storage_dirs = []
 
 for subdir in ('whisper', 'lists', 'rrd', 'log', 'log/webapp'):
-  storage_dirs.append( ('storage/%s' % subdir, []) )
+  storage_dirs.append( ('graphite/storage/%s' % subdir, []) )
 
 webapp_content = {}
 
-for root, dirs, files in os.walk('webapp/content'):
+for root, dirs, files in os.walk('graphite/webapp/content'):
   for filename in files:
     filepath = os.path.join(root, filename)
 
@@ -29,7 +29,7 @@
     webapp_content[root].append(filepath)
 
 
-conf_files = [ ('conf', glob('conf/*.example')) ]
+conf_files = [ ('/usr/local/etc/graphite', glob('conf/*.example')) ]
 
 setup(
   name='graphite-web',
