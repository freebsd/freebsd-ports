--- runTests.py.orig	2021-08-28 05:32:24 UTC
+++ runTests.py
@@ -107,7 +107,7 @@ def modelDependencies(tests):
 
 def makeTest(name, j):
     """Run the make command for a given single test."""
-    doCommand("make -j%d %s" % (j or 1, name))
+    doCommand("gmake -j%d %s" % (j or 1, name))
 
 
 def runTest(name):
