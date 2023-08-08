--- plugins/stockpile/payloads/ragdoll.py.orig	2023-05-16 23:53:18 UTC
+++ plugins/stockpile/payloads/ragdoll.py
@@ -63,7 +63,7 @@ class OperationLoop:
     def _execute_instruction(self, i):
         print('[+] Running instruction: %s' % i['id'])
         cmd = self._decode_bytes(i['command'])
-        execution_timestamp = datetime.datetime.now().strftime('%Y-%m-%d %H:%M:%S')
+        execution_timestamp = datetime.datetime.now().strftime('%Y-%m-%dT%H:%M:%SZ')
         try:
             output = subprocess.check_output(cmd, shell=True, timeout=i['timeout'])
         except subprocess.CalledProcessError as e:
