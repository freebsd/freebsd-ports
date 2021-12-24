--- setup.py.orig	2021-12-22 07:52:01 UTC
+++ setup.py
@@ -44,8 +44,8 @@ extra = dict(
     ],
 )
 
-if python_version >= 3.0:
-    extra["use_2to3"] = True
+#if python_version >= 3.0:
+#    extra["use_2to3"] = True
 
 # -- NICE-TO-HAVE:
 # # FILE: setup.cfg -- Use pytest-runner (ptr) as test runner.
