--- numpy/distutils/misc_util.py.orig	2022-01-02 20:27:35 UTC
+++ numpy/distutils/misc_util.py
@@ -92,9 +92,9 @@ def get_num_build_jobs():
 
     """
     from numpy.distutils.core import get_distribution
-    try:
-        cpu_count = len(os.sched_getaffinity(0))
-    except AttributeError:
-        cpu_count = multiprocessing.cpu_count()
+#    try:
+#        cpu_count = len(os.sched_getaffinity(0))
+#    except AttributeError:
+    cpu_count = multiprocessing.cpu_count()
     cpu_count = min(cpu_count, 8)
     envjobs = int(os.environ.get("NPY_NUM_BUILD_JOBS", cpu_count))
