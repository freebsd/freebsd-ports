--- setup.py.orig	2021-10-15 18:41:22 UTC
+++ setup.py
@@ -64,13 +64,13 @@ setup(
         'flask',
         'flask_cors',
         'flask_json',
-        'jsonlines==1.2.0',
+        'jsonlines>=1.2.0',
         'PyYAML>=5.1',
         'requests>=2.12.4',
         'tenacity>=5.1.1',
         'tqdm>=4.32',
-        'requests_futures==1.0.0',
-        'jsonschema==3.*',
+        'requests_futures>=1.0.0',
+        'jsonschema>=3,<5',
     ],
     extras_require={
         'pyarrow': [
