--- runTests.py.orig	2021-08-28 03:33:35 UTC
+++ runTests.py
@@ -172,7 +172,7 @@ def generateTests(j):
     if isWin():
         doCommand("mingw32-make -j%d generate-tests -s" % (j or 1))
     else:
-        doCommand("make -j%d generate-tests -s" % (j or 1))
+        doCommand("gmake -j%d generate-tests -s" % (j or 1))
 
 
 def divide_chunks(l, n):
