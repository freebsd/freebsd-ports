--- setup.py.orig	2014-06-04 05:08:20 UTC
+++ setup.py
@@ -13,10 +13,10 @@ setup(name='pypolicyd-spf',
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
