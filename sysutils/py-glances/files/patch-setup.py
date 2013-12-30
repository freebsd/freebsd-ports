--- ./setup.py.orig	2013-12-15 17:23:06.000000000 +0800
+++ ./setup.py	2013-12-16 21:45:25.000000000 +0800
@@ -9,8 +9,7 @@
 data_files = [
     ('share/doc/glances', ['AUTHORS', 'COPYING', 'NEWS', 'README.rst',
                            'conf/glances.conf', 'docs/glances-doc.html']),
-    ('share/doc/glances/images', glob.glob('docs/images/*.png')),
-    ('share/man/man1', ['man/glances.1'])
+    ('share/doc/glances/images', glob.glob('docs/images/*.png'))
 ]
 
 if hasattr(sys, 'real_prefix') or 'bsd' in sys.platform:
@@ -21,10 +20,6 @@
     conf_path = os.path.join('/usr/local', 'etc', 'glances')
 elif 'win32' in sys.platform:
     conf_path = os.path.join(os.environ.get('APPDATA'), 'glances')
-data_files.append((conf_path, ['conf/glances.conf']))
-
-for mo in glob.glob('i18n/*/LC_MESSAGES/*.mo'):
-    data_files.append((os.path.dirname(mo).replace('i18n/', 'share/locale/'), [mo]))
 
 if sys.platform.startswith('win'):
     requires = ['psutil>=0.5.1', 'colorconsole==0.6']
