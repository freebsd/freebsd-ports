--- setup.py.orig	2015-11-27 18:37:16 UTC
+++ setup.py
@@ -23,8 +23,6 @@ else:
         cf.add_section('install')
     except ConfigParser.DuplicateSectionError:
         pass
-    cf.set('install', 'prefix', '/opt/graphite')
-    cf.set('install', 'install-lib', '%(prefix)s/webapp')
 
 with open('setup.cfg', 'wb') as f:
     cf.write(f)
@@ -41,11 +39,11 @@ else:
 storage_dirs = []
 
 for subdir in ('whisper', 'rrd', 'log', 'log/webapp'):
-  storage_dirs.append( ('storage/%s' % subdir, []) )
+  storage_dirs.append( ('graphite/storage/%s' % subdir, []) )
 
 webapp_content = {}
 
-for root, dirs, files in os.walk('webapp/content'):
+for root, dirs, files in os.walk('graphite/webapp/content'):
   for filename in files:
     filepath = os.path.join(root, filename)
 
@@ -55,7 +53,7 @@ for root, dirs, files in os.walk('webapp
     webapp_content[root].append(filepath)
 
 
-conf_files = [ ('conf', glob('conf/*.example')) ]
+conf_files = [ ('%%PREFIX%%/etc/graphite', glob('conf/*.example')) ]
 examples = [ ('examples', glob('examples/example-*')) ]
 
 try:
@@ -87,7 +85,7 @@ try:
       package_data={'graphite' :
         ['templates/*', 'local_settings.py.example']},
       scripts=glob('bin/*'),
-      data_files=webapp_content.items() + storage_dirs + conf_files + examples,
+      data_files=conf_files,
       **setup_kwargs
     )
 finally:
