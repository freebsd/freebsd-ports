This is only a cosmetic patch as it fixes docs and not execution

--- google_compute_engine/boto/compute_auth.py.orig	2017-07-23 07:12:16 UTC
+++ google_compute_engine/boto/compute_auth.py
@@ -29,7 +29,7 @@ GS_SCOPES = set([
 class ComputeAuth(auth_handler.AuthHandler):
   """Google Compute service account auth handler.
 
-  The boto library reads the system config file (/etc/boto.cfg) and looks
+  The boto library reads the system config file (%%PREFIX%%/etc/boto.cfg) and looks
   at a config value called 'plugin_directory'. It then loads the Python
   files and find classes derived from boto.auth_handler.AuthHandler.
   """
