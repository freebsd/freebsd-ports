--- runTests.py.orig	2026-05-20 05:57:17 UTC
+++ runTests.py
@@ -185,7 +185,7 @@ def generateTests(j):
 
 def generateTests(j):
     """Generate all tests and pass along the j parameter to make."""
-    doCommand("make -j%d generate-tests -s" % (j or 1))
+    doCommand("gmake -j%d generate-tests -s" % (j or 1))
 
 
 def divide_chunks(l, n):
@@ -243,7 +243,7 @@ def makeTest(name, j):
 
 def makeTest(name, j):
     """Run the make command for a given single test."""
-    doCommand("make -j%d %s" % (j or 1, name))
+    doCommand("gmake -j%d %s" % (j or 1, name))
 
 
 def commandExists(command):
