--- google_compute_engine/metadata_scripts/script_executor.py.orig	2018-02-22 19:44:17 UTC
+++ google_compute_engine/metadata_scripts/script_executor.py
@@ -53,7 +53,7 @@ class ScriptExecutor(object):
     """
     process = subprocess.Popen(
         metadata_script, shell=True,
-        executable=constants.LOCALBASE + '/bin/bash',
+        executable='/bin/sh',
         stderr=subprocess.STDOUT, stdout=subprocess.PIPE)
     while True:
       for line in iter(process.stdout.readline, b''):
