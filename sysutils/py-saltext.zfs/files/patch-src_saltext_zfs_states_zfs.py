--- src/saltext/zfs/states/zfs.py.orig	2026-08-06 18:58:31 UTC
+++ src/saltext/zfs/states/zfs.py
@@ -440,6 +440,7 @@ def _dataset_present(
             fields="value",
             depth=0,
             parsable=True,
+            source="default,inherited,local,none,received",
         ).get(name, OrderedDict())
 
         ## NOTE: build list of properties to update
@@ -503,6 +504,8 @@ def _dataset_present(
             )
         else:
             ## NOTE: create the dataset
+            if volume_size:
+                del properties["volsize"]
             mod_res = __salt__["zfs.create"](
                 name,
                 **{
