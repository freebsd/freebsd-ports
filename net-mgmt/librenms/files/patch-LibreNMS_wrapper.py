--- LibreNMS/wrapper.py.orig	2023-10-27 13:10:42 UTC
+++ LibreNMS/wrapper.py
@@ -282,7 +282,7 @@ def poll_worker(
                     os.path.dirname(os.path.dirname(os.path.realpath(__file__))),
                     wrappers[wrapper_type]["executable"],
                 )
-                command = "/usr/bin/env php {} {} {}".format(
+                command = ""%%LOCALBASE%%/bin/php {} {} {}".format(
                     executable, wrappers[wrapper_type]["option"], device_id
                 )
                 if modules is not None and len(str(modules).strip()):
