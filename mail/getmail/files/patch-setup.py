--- setup.py.orig
+++ setup.py
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
@@ -97,24 +96,6 @@
     'getmail_mbox'
     ],
     data_files=[
-        (GETMAILDOCDIR, [
-            './README',
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
             'docs/getmail_maildir.1',
