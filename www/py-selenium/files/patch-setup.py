--- setup.py.orig	2017-03-18 23:33:26 UTC
+++ setup.py
@@ -73,9 +73,7 @@ setup_args = {
         'selenium.webdriver.firefox': ['*.xpi', 'webdriver_prefs.json'],
         'selenium.webdriver.remote': ['getAttribute.js', 'isDisplayed.js'],
     },
-    'data_files': [('selenium/webdriver/firefox/x86', ['selenium/webdriver/firefox/x86/x_ignore_nofocus.so']),
-                   ('selenium/webdriver/firefox/amd64', ['selenium/webdriver/firefox/amd64/x_ignore_nofocus.so']),
-                   ('selenium/webdriver/remote', ['selenium/webdriver/remote/getAttribute.js']),
+    'data_files': [('selenium/webdriver/remote', ['selenium/webdriver/remote/getAttribute.js']),
                    ('selenium/webdriver/remote', ['selenium/webdriver/remote/isDisplayed.js'])],
     'include_package_data': True,
     'zip_safe': False
