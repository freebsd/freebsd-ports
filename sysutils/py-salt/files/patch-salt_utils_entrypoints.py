--- salt/utils/entrypoints.py.orig	2022-09-26 21:22:01 UTC
+++ salt/utils/entrypoints.py
@@ -38,13 +38,20 @@ def iter_entry_points(group, name=None):
     entry_points_listing = []
     entry_points = importlib_metadata.entry_points()
 
-    for entry_point_group, entry_points_list in entry_points.items():
-        if entry_point_group != group:
-            continue
-        for entry_point in entry_points_list:
+    try:
+        for entry_point in entry_points.select(group=group):
             if name is not None and entry_point.name != name:
                 continue
             entry_points_listing.append(entry_point)
+    except AttributeError:
+        # importlib-metadata<5.0.0
+        for entry_point_group, entry_points_list in entry_points.items():
+            if entry_point_group != group:
+                continue
+            for entry_point in entry_points_list:
+                if name is not None and entry_point.name != name:
+                    continue
+                entry_points_listing.append(entry_point)
 
     return entry_points_listing
 
