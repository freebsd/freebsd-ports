--- peering_manager/configuration.example.py.orig	2025-09-05 10:59:41 UTC
+++ peering_manager/configuration.example.py
@@ -9,7 +9,7 @@ ALLOWED_HOSTS = ["*"]
 # A random one can be generated with Python in the Peering Manager venv with
 # from django.core.management.utils import get_random_secret_key
 # get_random_secret_key()
-SECRET_KEY = "ef7npku*djrj_r4jt4cojo8^j@2($$@05e(eq_mn!ywx*jg0vy"
+#SECRET_KEY = "<GENERATE A KEY>"
 
 # Base URL path if accessing Peering Manager within a directory.
 BASE_PATH = ""
