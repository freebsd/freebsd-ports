--- LibreNMS/wrapper.py.orig	2023-07-30 23:13:00 UTC
+++ LibreNMS/wrapper.py
@@ -278,7 +278,7 @@ def poll_worker(
                     os.path.dirname(os.path.dirname(os.path.realpath(__file__))),
                     wrappers[wrapper_type]["executable"],
                 )
-                command = "/usr/bin/env php {} -h {}".format(executable, device_id)
+                command = "/usr/local/bin/php {} -h {}".format(executable, device_id)
                 if debug:
                     command = command + " -d"
                 exit_code, output = command_runner(
