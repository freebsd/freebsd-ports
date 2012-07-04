--- setup.py.ori	2012-06-21 15:38:54.044808453 -0700
+++ setup.py	2012-06-21 15:41:16.067809618 -0700
@@ -15,11 +15,11 @@
 storage_dirs = []
 
 for subdir in ('whisper', 'rrd', 'log', 'log/webapp'):
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
 examples = [ ('examples', glob('examples/example-*')) ]
 
 setup(
