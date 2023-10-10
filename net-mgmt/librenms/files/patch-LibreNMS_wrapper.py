--- LibreNMS/wrapper.py.orig	2023-08-21 15:25:48 UTC
+++ LibreNMS/wrapper.py
@@ -280,7 +280,7 @@ def poll_worker(
                     os.path.dirname(os.path.dirname(os.path.realpath(__file__))),
                     wrappers[wrapper_type]["executable"],
                 )
-                command = "/usr/bin/env php {} -h {}".format(executable, device_id)
+                command = "%%LOCALBASE%%/bin/php php {} -h {}".format(executable, device_id)
                 if modules is not None and len(str(modules).strip()):
                     module_str = re.sub("\s", "", str(modules).strip())
                     command = command + " -m {}".format(module_str)
