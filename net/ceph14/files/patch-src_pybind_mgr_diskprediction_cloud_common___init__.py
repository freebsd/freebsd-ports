--- src/pybind/mgr/diskprediction_cloud/common/__init__.py.orig	2020-02-17 22:23:19.281206000 +0100
+++ src/pybind/mgr/diskprediction_cloud/common/__init__.py	2020-02-17 22:23:29.293335000 +0100
@@ -29,7 +29,7 @@
     pass
 
 
-def timeout(seconds=10, error_message=os.strerror(errno.ETIME)):
+def timeout(seconds=10, error_message=os.strerror(errno.ETIMEDOUT)):
     def decorator(func):
         def _handle_timeout(signum, frame):
             raise TimeoutError(error_message)
