Obtained from:	https://github.com/giampaolo/psutil/commit/04794aa03cb9d30287e8e7fd9c80acc8c4f2aa46

--- psutil/arch/freebsd/cpu.c.orig	2025-12-14 20:10:53 UTC
+++ psutil/arch/freebsd/cpu.c
@@ -149,7 +149,7 @@ psutil_cpu_freq(PyObject *self, PyObject *args) {
     int current;
     int core;
     char sensor[26];
-    char available_freq_levels[1000];
+    char available_freq_levels[1000] = {0};
     size_t size;
 
     if (!PyArg_ParseTuple(args, "i", &core))
