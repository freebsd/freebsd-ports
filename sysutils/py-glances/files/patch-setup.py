--- ./setup.py.orig	2013-11-01 17:12:25.000000000 +0800
+++ ./setup.py	2013-11-08 14:42:57.000000000 +0800
@@ -11,10 +11,9 @@
                            'docs/glances-doc.html',
                            'glances/conf/glances.conf']),
     ('share/doc/glances/images', glob.glob('docs/images/*.png')),
-    ('share/glances/css', glob.glob('glances/data/css/*.css')),
-    ('share/glances/html', glob.glob('glances/data/html/*.html')),
-    ('share/glances/img', glob.glob('glances/data/img/*.png')),
-    ('share/man/man1', ['docs/man/glances.1'])
+    ('glances/data/css', glob.glob('glances/data/css/*.css')),
+    ('glances/data/html', glob.glob('glances/data/html/*.html')),
+    ('glances/data/img', glob.glob('glances/data/img/*.png')),
 ]
 
 if hasattr(sys, 'real_prefix') or 'bsd' in sys.platform:
@@ -25,10 +24,6 @@
     conf_path = os.path.join('/usr/local', 'etc', 'glances')
 elif 'win32' in sys.platform:
     conf_path = os.path.join(os.environ.get('APPDATA'), 'glances')
-data_files.append((conf_path, ['glances/conf/glances.conf']))
-
-for mo in glob.glob('i18n/*/LC_MESSAGES/*.mo'):
-    data_files.append((os.path.dirname(mo).replace('i18n/', 'share/locale/'), [mo]))
 
 if sys.platform.startswith('win'):
     requires = ['psutil>=0.5.1', 'colorconsole==0.6']
