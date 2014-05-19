--- src/doc/common/custom-sphinx-build.py-orig	2014-05-15 19:16:13.000000000 +0000
+++ src/doc/common/custom-sphinx-build.py	2014-05-15 19:17:11.000000000 +0000
@@ -207,4 +207,5 @@
 if ERROR_MESSAGE and ABORT_ON_ERROR:
     sys.stdout.flush()
     sys.stderr.flush()
-    raise OSError(ERROR_MESSAGE)
+    # Comment out next line so that warnings don't stop doc build.
+    # raise OSError(ERROR_MESSAGE)
