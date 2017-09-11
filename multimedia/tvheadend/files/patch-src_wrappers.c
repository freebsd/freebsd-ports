--- src/wrappers.c.orig	2017-05-16 11:15:24.000000000 +0000
+++ src/wrappers.c	2017-06-21 18:00:42.352871000 +0000
@@ -290,6 +290,19 @@
   } while (r > 0);
 }
 
+#ifdef PLATFORM_FREEBSD
+int64_t
+tvh_usleep(int64_t us)
+{
+  return usleep(us);
+}
+
+int64_t
+tvh_usleep_abs(int64_t us)
+{
+  return usleep(us - getfastmonoclock());
+}
+#else
 int64_t
 tvh_usleep(int64_t us)
 {
@@ -323,6 +336,7 @@
     return val;
   return r ? -r : 0;
 }
+#endif
 
 /*
  * qsort
