This patch won't be necessary anymore in further versions.
See https://github.com/GoogleCloudPlatform/compute-image-packages/pull/440

--- google_compute_engine/metadata_scripts/script_executor.py.orig	2017-07-23 07:12:16 UTC
+++ google_compute_engine/metadata_scripts/script_executor.py
@@ -50,7 +50,7 @@ class ScriptExecutor(object):
       metadata_script: string, the file location of an executable script.
     """
     process = subprocess.Popen(
-        metadata_script, shell=True, executable='/bin/bash',
+        metadata_script, shell=True, executable='%%PREFIX%%/bin/bash',
         stderr=subprocess.STDOUT, stdout=subprocess.PIPE)
     while True:
       for line in iter(process.stdout.readline, b''):
