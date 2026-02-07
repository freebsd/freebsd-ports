--- setup.py.orig	2020-11-02 15:56:08 UTC
+++ setup.py
@@ -88,23 +88,6 @@ setup(
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
