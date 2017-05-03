--- setup.py.orig	2017-04-30 10:33:38 UTC
+++ setup.py
@@ -36,7 +36,6 @@ version = meta['version']
 # https://github.com/pypa/pip/issues/988 for more info.
 install_requires = [
     'acme=={0}'.format(version),
-    'argparse',
     # We technically need ConfigArgParse 0.10.0 for Python 2.6 support, but
     # saying so here causes a runtime error against our temporary fork of 0.9.3
     # in which we added 2.6 support (see #2243), so we relax the requirement.
@@ -56,6 +55,10 @@ install_requires = [
     'zope.interface',
 ]
 
+# env markers cause problems with older pip and setuptools
+if sys.version_info < (2, 7):
+    install_requires.append('argparse')
+
 dev_extras = [
     # Pin astroid==1.3.5, pylint==1.4.2 as a workaround for #289
     'astroid==1.3.5',
