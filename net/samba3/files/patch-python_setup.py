--- python/setup.py.orig	Tue May 15 13:41:41 2007
+++ python/setup.py	Tue May 15 13:43:03 2007
@@ -67,6 +67,8 @@
         libraries.append(lib[2:])
     elif lib[0:8] == ("-pthread"):
         pass # Skip linker flags
+    elif lib[0:4] == ("-pie"):
+        pass # Skip linker flags
     elif lib[0:2] == "-L":
         library_dirs.append(lib[2:])
     elif lib[0:2] in ("-W","-s"):
