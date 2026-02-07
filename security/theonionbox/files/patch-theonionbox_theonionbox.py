--- theonionbox/theonionbox.py.orig	2019-11-09 13:37:29 UTC
+++ theonionbox/theonionbox.py
@@ -513,7 +513,7 @@ required_modules = {
         'info': "Check 'https://pypi.python.org/pypi/psutil' for installation instructions."
     },
     'stem': {
-        'version': '>=1.5.4, <=1.6'
+        'version': '>=1.5.4'
     },
     'bottle': {
         'version': '>=0.12.13'
@@ -539,7 +539,7 @@ required_modules = {
         'version': '>=3.2; python_version<"3.0"'
     },
     'urllib3': {
-        'version': '>=1.24.2, <1.25'
+        'version': '>=1.21.1,<1.26'    #copied (except the exclusions) from requests 2.22
     }
 }
 
