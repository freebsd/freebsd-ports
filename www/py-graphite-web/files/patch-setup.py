--- setup.py.orig	2013-08-21 17:11:04.000000000 +0000
+++ setup.py	2014-02-14 04:44:44.290189349 +0000
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
@@ -60,6 +60,6 @@
   package_data={'graphite' :
     ['templates/*', 'local_settings.py.example']},
   scripts=glob('bin/*'),
-  data_files=webapp_content.items() + storage_dirs + conf_files + examples,
+  data_files=conf_files,
   **setup_kwargs
 )
