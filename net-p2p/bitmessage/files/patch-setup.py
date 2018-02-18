--- setup.py.orig	2017-03-01 12:12:31 UTC
+++ setup.py
@@ -117,13 +117,7 @@ def detectOS():
 def detectPrereqs(missing=False):
     available = []
     for module in packageName.keys():
-        try:
-            import_module(module)
-            if not missing:
-                available.append(module)
-        except ImportError:
-            if missing:
-                available.append(module)
+        available.append(module)
     return available
 
 
@@ -146,7 +140,7 @@ def compilerToPackages():
 if __name__ == "__main__":
     detectOS.result = None
     detectPrereqs.result = None
-    if detectPrereqs(True) != [] and detectOS() in packageManager:
+    if False and detectPrereqs(True) != [] and detectOS() in packageManager:
         if detectOS() is not None:
             print "It looks like you're using %s. " \
                 "It is highly recommended to use the package manager " \
@@ -159,7 +153,7 @@ if __name__ == "__main__":
         print "It looks like you're missing setuptools."
         sys.exit()
 
-    if detectPrereqs(True) != []:
+    if False and detectPrereqs(True) != []:
         print "Press Return to continue"
         try:
             nothing = raw_input()
