--- setup.py.orig	2007-11-23 08:26:55.000000000 -0800
+++ setup.py	2008-02-05 09:24:03.000000000 -0800
@@ -39,12 +39,11 @@
     datadir or prefix,
     'share',
     'doc',
-    'getmail-%s' % __version__
+    'getmail'
 )
 
 GETMAILMANDIR = os.path.join(
     datadir or prefix,
-    'share',
     'man',
     'man1'
 )
@@ -98,25 +97,6 @@
     'getmail_mbox'
     ],
     data_files=[
-        (GETMAILDOCDIR, [
-            './README',
-            './getmail.spec',
-            'docs/BUGS',
-            'docs/COPYING',
-            'docs/CHANGELOG',
-            'docs/TODO',
-            'docs/THANKS',
-            'docs/configuration.html',
-            'docs/configuration.txt',
-            'docs/documentation.html',
-            'docs/documentation.txt',
-            'docs/faq.html',
-            'docs/faq.txt',
-            'docs/getmaildocs.css',
-            'docs/getmailrc-examples',
-            'docs/troubleshooting.html',
-            'docs/troubleshooting.txt',
-        ]),
         (GETMAILMANDIR, [
             'docs/getmail.1',
             'docs/getmail_fetch.1',
