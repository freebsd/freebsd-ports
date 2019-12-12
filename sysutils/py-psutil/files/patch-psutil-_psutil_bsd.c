--- psutil/_psutil_bsd.c.orig	2019-11-20 08:39:49 UTC
+++ psutil/_psutil_bsd.c
@@ -271,7 +271,11 @@ psutil_proc_oneshot_info(PyObject *self, PyObject *arg
 
     // Return a single big tuple with all process info.
     py_retlist = Py_BuildValue(
+#if defined(__FreeBSD_version) && __FreeBSD_version >= 1200031
+        "(lillllllLdllllddddlllllbO)",
+#else
         "(lillllllidllllddddlllllbO)",
+#endif
 #ifdef PSUTIL_FREEBSD
         //
         (long)kp.ki_ppid,                // (long) ppid
@@ -285,7 +289,7 @@ psutil_proc_oneshot_info(PyObject *self, PyObject *arg
         (long)kp.ki_groups[0],           // (long) effective gid
         (long)kp.ki_svuid,               // (long) saved gid
         //
-        kp.ki_tdev,                      // (int) tty nr
+        kp.ki_tdev,                      // (int or long long) tty nr
         PSUTIL_TV2DOUBLE(kp.ki_start),   // (double) create time
         // ctx switches
         kp.ki_rusage.ru_nvcsw,           // (long) ctx switches (voluntary)
