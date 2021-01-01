--- setup.py.orig	2009-01-08 21:55:25 UTC
+++ setup.py
@@ -39,12 +39,11 @@ GETMAILDOCDIR = os.path.join(
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
@@ -98,25 +97,6 @@ setup(
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
