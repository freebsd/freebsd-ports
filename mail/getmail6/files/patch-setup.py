--- setup.py.orig      2020-08-30 11:47:16 UTC
+++ setup.py
@@ -85,23 +85,6 @@ setup(
         'getmail-gmail-xoauth-tokens',
     ],
     data_files=[
-        (DOCDIR, [
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
         (MANDIR, [
             'docs/getmail.1',
             'docs/getmail_fetch.1',
