--- vendor/trezor-common/tools/coin_info.py.orig	2018-11-08 13:20:31 UTC
+++ vendor/trezor-common/tools/coin_info.py
@@ -25,7 +25,7 @@ def load_json(*path):
     else:
         filename = os.path.join(DEFS_DIR, *path)
 
-    with open(filename) as f:
+    with open(filename, encoding="utf-8") as f:
         return json.load(f, object_pairs_hook=OrderedDict)
 
 
