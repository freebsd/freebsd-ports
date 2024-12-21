--- python/mozversioncontrol/mozversioncontrol/__init__.py.orig	2024-12-13 13:44:42 UTC
+++ python/mozversioncontrol/mozversioncontrol/__init__.py
@@ -1019,9 +1019,10 @@ class SrcRepository(Repository):
         """
         res = []
         # move away the .git or .hg folder from path to more easily test in a hg/git repo
-        for root, dirs, files in os.walk("."):
+        for root, dirs, files in os.walk(self.path):
+            base = os.path.relpath(root, self.path)
             for name in files:
-                res.append(os.path.join(root, name))
+                res.append(os.path.join(base, name))
         return res
 
     def get_tracked_files_finder(self, path):
