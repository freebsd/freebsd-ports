--- plugins/stockpile/app/obfuscators/steganography.py.orig	2022-09-14 02:24:22 UTC
+++ plugins/stockpile/app/obfuscators/steganography.py
@@ -14,7 +14,8 @@ class Obfuscation(BaseObfuscator):
     def supported_platforms(self):
         return dict(
             darwin=['sh'],
-            linux=['sh']
+            linux=['sh'],
+            freebsd=['sh']
         )
 
     """ EXECUTORS """
