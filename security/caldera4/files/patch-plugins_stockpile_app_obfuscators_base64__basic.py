--- plugins/stockpile/app/obfuscators/base64_basic.py.orig	2022-09-14 02:24:22 UTC
+++ plugins/stockpile/app/obfuscators/base64_basic.py
@@ -10,7 +10,8 @@ class Obfuscation(BaseObfuscator):
         return dict(
             windows=['psh'],
             darwin=['sh'],
-            linux=['sh']
+            linux=['sh'],
+            freebsd=['sh']
         )
 
     """ EXECUTORS """
