--- setup.py.orig	2021-11-30 13:38:11 UTC
+++ setup.py
@@ -23,12 +23,12 @@ def get_version():
 
 def get_install_requires():
     res = ['elasticsearch>=7.12.0,<8.0.0' ]
-    res.append('urllib3==1.26.4')
+    res.append('urllib3>=1.26.4')
     res.append('requests>=2.25.1')
     res.append('boto3>=1.17.57')
     res.append('requests_aws4auth>=1.0.1')
     res.append('click>=7.0,<8.0')
-    res.append('pyyaml==5.4.1')
+    res.append('pyyaml>=5.4.1')
     res.append('voluptuous>=0.12.1')
     res.append('certifi>=2020.12.5')
     res.append('six>=1.15.0')
