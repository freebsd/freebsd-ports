--- src/igraph/configuration.py.orig	2020-10-08 10:13:28 UTC
+++ src/igraph/configuration.py
@@ -56,6 +56,18 @@ def get_platform_image_viewer():
                 if os.path.isfile(full_path):
                     return full_path
         return ""
+    elif plat == "FreeBSD":
+        # FreeBSD also has a whole lot of choices, try to find one
+        choices = ["eog", "gthumb", "geeqie", "display",
+                   "gpicview", "gwenview", "qiv", "gimv", "ristretto",
+                   "geeqie", "eom"]
+        paths = ["%%LOCALBASE%%/bin"]
+        for path in paths:
+            for choice in choices:
+                full_path = os.path.join(path, choice)
+                if os.path.isfile(full_path):
+                    return full_path
+        return ""
     elif plat == "Windows" or plat == "Microsoft":    # Thanks to Dale Hunscher
         # Use the built-in Windows image viewer, if available
         return "start"
