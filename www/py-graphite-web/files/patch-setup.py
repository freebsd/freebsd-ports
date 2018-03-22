--- setup.py.orig	2018-02-13 06:01:34.000000000 -0500
+++ setup.py	2018-03-22 09:16:21.606146000 -0400
@@ -39,10 +39,6 @@
         cf.add_section('install')
     except DuplicateSectionError:
         pass
-    if not cf.has_option('install', 'prefix'):
-        cf.set('install', 'prefix', '/opt/graphite')
-    if not cf.has_option('install', 'install-lib'):
-        cf.set('install', 'install-lib', '%(prefix)s/webapp')
 
 with open('setup.cfg', 'w') as f:
     cf.write(f)
@@ -59,16 +55,16 @@
 storage_dirs = []
 
 for subdir in ('whisper', 'ceres', 'rrd', 'log', 'log/webapp'):
-  storage_dirs.append( ('storage/%s' % subdir, []) )
+  storage_dirs.append( ('graphite/storage/%s' % subdir, []) )
 
 webapp_content = defaultdict(list)
 
-for root, dirs, files in os.walk('webapp/content'):
+for root, dirs, files in os.walk('graphite/webapp/content'):
   for filename in files:
     filepath = os.path.join(root, filename)
     webapp_content[root].append(filepath)
 
-conf_files = [ ('conf', glob('conf/*.example')) ]
+conf_files = [ ('/usr/local/etc/graphite', glob('conf/*.example')) ]
 examples = [ ('examples', glob('examples/example-*')) ]
 
 try:
@@ -108,7 +104,7 @@
       package_data={'graphite' :
         ['templates/*', 'local_settings.py.example']},
       scripts=glob('bin/*'),
-      data_files=list(webapp_content.items()) + storage_dirs + conf_files + examples,
+      data_files=list(conf_files),
       install_requires=['Django>=1.8,<1.11.99', 'django-tagging==0.4.3', 'pytz', 'pyparsing', 'cairocffi', 'urllib3', 'scandir', 'six'],
       classifiers=[
           'Intended Audience :: Developers',
