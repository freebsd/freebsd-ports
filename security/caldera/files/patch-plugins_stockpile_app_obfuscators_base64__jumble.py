--- plugins/stockpile/app/obfuscators/base64_jumble.py.orig	2022-09-14 02:24:22 UTC
+++ plugins/stockpile/app/obfuscators/base64_jumble.py
@@ -14,7 +14,8 @@ class Obfuscation(BaseObfuscator):
         return dict(
             windows=['psh'],
             darwin=['sh'],
-            linux=['sh']
+            linux=['sh'],
+            freebsd=['sh']
         )
 
     def run(self, link, **kwargs):
