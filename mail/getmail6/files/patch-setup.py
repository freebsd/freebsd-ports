--- setup.py.orig	2020-08-18 15:00:41 UTC
+++ setup.py
@@ -35,12 +35,11 @@ GETMAILDOCDIR = os.path.join(
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
@@ -96,23 +95,6 @@ setup(
         'getmail-gmail-xoauth-tokens',
     ],
     data_files=[
-        (GETMAILDOCDIR, [
-            './README',
-            'docs/BUGS',
-            'docs/COPYING',
-            'docs/CHANGELOG',
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
