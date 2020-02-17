# freenit works fine with flask-cors 2.x
# TODO: Upstream

--- setup.py.orig	2020-02-17 10:42:25 UTC
+++ setup.py
@@ -43,7 +43,7 @@ setup(
     install_requires=[
         'bcrypt',
         'flask-collect>=1.3.2',
-        'flask-cors>=3.0.8',
+        'flask-cors>=2.1.2',
         'flask-jwt-extended>=3.24.1',
         'flask-security>=3.0.0',
         'flask-smorest>=0.18.2',
