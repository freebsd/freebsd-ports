--- ./setup.py.orig	2010-11-17 11:11:03.000000000 +0300
+++ ./setup.py	2012-10-01 13:36:11.000000000 +0400
@@ -14,8 +14,7 @@
       url='http://code.google.com/p/pyang',
       scripts=['bin/pyang', 'bin/yang2html', 'bin/yang2dsdl'],
       packages=['pyang', 'pyang.plugins', 'pyang.translators'],
-      data_files=[('.', ['LICENSE']),
-                  ('share/man/man1', ['man/man1/pyang.1',
+      data_files=[('man/man1', ['man/man1/pyang.1',
                                       'man/man1/yang2dsdl.1']),
                   ('share/yang/modules', modules),
                   ('share/yang/xslt', xslt),
