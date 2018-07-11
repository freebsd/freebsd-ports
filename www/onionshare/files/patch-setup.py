--- setup.py.orig	2018-07-11 06:12:43 UTC
+++ setup.py
@@ -54,7 +54,7 @@ data_files=[
         (os.path.join(sys.prefix, 'share/onionshare/locale'), file_list('share/locale')),
         (os.path.join(sys.prefix, 'share/onionshare/html'), file_list('share/html')),
     ]
-if platform.system() != 'OpenBSD':
+if not platform.system().endswith('BSD'):
     data_files.append(('/usr/share/nautilus-python/extensions/', ['install/scripts/onionshare-nautilus.py']))
 
 setup(
