--- os/utils.c.orig	2014-04-15 01:01:57 UTC
+++ os/utils.c
@@ -443,11 +443,11 @@ GetTimeInMillis(void)
     static clockid_t clockid;
 
     if (!clockid) {
-#ifdef CLOCK_MONOTONIC_COARSE
-        if (clock_getres(CLOCK_MONOTONIC_COARSE, &tp) == 0 &&
+#ifdef CLOCK_MONOTONIC_FAST
+        if (clock_getres(CLOCK_MONOTONIC_FAST, &tp) == 0 &&
             (tp.tv_nsec / 1000) <= 1000 &&
-            clock_gettime(CLOCK_MONOTONIC_COARSE, &tp) == 0)
-            clockid = CLOCK_MONOTONIC_COARSE;
+            clock_gettime(CLOCK_MONOTONIC_FAST, &tp) == 0)
+            clockid = CLOCK_MONOTONIC_FAST;
         else
 #endif
         if (clock_gettime(CLOCK_MONOTONIC, &tp) == 0)
