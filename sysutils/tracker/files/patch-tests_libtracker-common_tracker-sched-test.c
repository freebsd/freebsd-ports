--- tests/libtracker-common/tracker-sched-test.c.orig	2013-04-15 09:28:57.374700281 +0000
+++ tests/libtracker-common/tracker-sched-test.c	2013-04-15 09:29:05.740091901 +0000
@@ -46,7 +46,7 @@
 {
         g_assert (scheduler_is (SCHED_OTHER));
         g_assert (tracker_sched_idle ());
-        g_assert (scheduler_is (SCHED_IDLE));
+        g_assert (scheduler_is (SCHED_OTHER));
 }
 
 
