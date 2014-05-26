--- ./preppy.py.orig	2014-05-25 20:05:05.000000000 +0300
+++ ./preppy.py	2014-05-25 20:06:13.000000000 +0300
@@ -871,7 +871,7 @@
 
 def testgetmodule(name="testoutput"):
     #name = "testpreppy"
-    pel("trying to load", name)
+    pel("trying to load " + name)
     result = getPreppyModule(name, verbose=1)
     pel( "load successful! running result")
     pel("=" * 100)
