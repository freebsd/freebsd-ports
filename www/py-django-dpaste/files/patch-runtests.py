--- runtests.py.orig	2016-08-15 03:40:49 UTC
+++ runtests.py
@@ -63,8 +63,7 @@ def runtests(*test_args):
 
     test_runner = TestRunner(verbosity=1)
     failures = test_runner.run_tests(['dpaste'])
-    if failures:
-        sys.exit(failures)
+    sys.exit(failures)
 
 if __name__ == '__main__':
     runtests(*sys.argv[1:])
