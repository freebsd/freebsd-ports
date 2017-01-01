--- setup.py.orig	2016-12-29 00:15:54 UTC
+++ setup.py
@@ -71,9 +71,7 @@ setup_args = {
         'selenium.webdriver.firefox': ['*.xpi', 'webdriver_prefs.json'],
         'selenium.webdriver.remote': ['getAttribute.js', 'isDisplayed.js'],
     },
-    'data_files': [('selenium/webdriver/firefox/x86', ['py/selenium/webdriver/firefox/x86/x_ignore_nofocus.so']),
-                   ('selenium/webdriver/firefox/amd64', ['py/selenium/webdriver/firefox/amd64/x_ignore_nofocus.so']),
-                   ('selenium/webdriver/remote', ['py/selenium/webdriver/remote/getAttribute.js']),
+    'data_files': [('selenium/webdriver/remote', ['py/selenium/webdriver/remote/getAttribute.js']),
                    ('selenium/webdriver/remote', ['py/selenium/webdriver/remote/isDisplayed.js'])],
     'include_package_data': True,
     'zip_safe': False
