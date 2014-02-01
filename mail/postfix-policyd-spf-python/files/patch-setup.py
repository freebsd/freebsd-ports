--- setup.py.orig	2013-05-14 12:57:04.000000000 +0900
+++ setup.py	2014-01-14 10:15:11.000000000 +0900
@@ -13,10 +13,10 @@
       py_modules=['policydspfsupp', 'policydspfuser'],
       keywords = ['Postfix','spf','email'],
       scripts = ['policyd-spf'],
-      data_files=[(os.path.join('share', 'man', 'man1'),
-          ['policyd-spf.1']), (os.path.join('share', 'man', 'man5'),
-          ['policyd-spf.conf.5']), (os.path.join('/etc', 'python-policyd-spf'),
-          ['policyd-spf.conf']), (os.path.join('share', 'man', 'man5'),
+      data_files=[(os.path.join('man', 'man1'),
+          ['policyd-spf.1']), (os.path.join('man', 'man5'),
+          ['policyd-spf.conf.5']), (os.path.join('etc', 'postfix-policyd-spf-python'),
+          ['policyd-spf.conf.sample']), (os.path.join('man', 'man5'),
           ['policyd-spf.peruser.5'])],
       classifiers = [
         'Development Status :: 5 - Production/Stable',
