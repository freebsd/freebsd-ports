--- ./setup.py.orig	2014-06-16 10:56:37.000000000 +0800
+++ ./setup.py	2014-06-16 10:57:02.000000000 +0800
@@ -11,8 +11,7 @@
     data_files = [
         ('share/doc/glances', ['AUTHORS', 'COPYING', 'NEWS', 'README.rst',
                                'conf/glances.conf', 'docs/glances-doc.html']),
-        ('share/doc/glances/images', glob.glob('docs/images/*.png')),
-        ('share/man/man1', ['man/glances.1'])
+        ('share/doc/glances/images', glob.glob('docs/images/*.png'))
     ]
 
     if hasattr(sys, 'real_prefix') or 'bsd' in sys.platform:
@@ -23,10 +22,6 @@
         conf_path = os.path.join('/usr/local', 'etc', 'glances')
     elif 'win32' in sys.platform:
         conf_path = os.path.join(os.environ.get('APPDATA'), 'glances')
-    data_files.append((conf_path, ['conf/glances.conf']))
-
-    for mo in glob.glob('i18n/*/LC_MESSAGES/*.mo'):
-        data_files.append((os.path.dirname(mo).replace('i18n/', 'share/locale/'), [mo]))
 
     return data_files
 
