Let users decide to install the examples files via the EXAMPLES option.

--- setup.py.orig	2022-05-08 10:57:35 UTC
+++ setup.py
@@ -39,10 +39,6 @@ m['data_files'] = [
         'share/man/man7/urlwatch-deprecated.7',
         'share/man/man7/urlwatch-intro.7',
     ]),
-    ('share/urlwatch/examples', [
-        'share/urlwatch/examples/hooks.py.example',
-        'share/urlwatch/examples/urls.yaml.example',
-    ]),
 ]
 m['project_urls'] = {
     'Source': 'https://github.com/thp/urlwatch',
