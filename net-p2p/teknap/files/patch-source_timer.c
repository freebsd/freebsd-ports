--- source/timer.c.orig	2007-11-12 15:43:52.000000000 +0100
+++ source/timer.c	2007-11-12 15:44:47.000000000 +0100
@@ -145,7 +145,7 @@
  * This is put here on purpose -- we dont want any of the above functions
  * to have any knowledge of this struct.
  */
-static TimerList *PendingTimers;
+TimerList *PendingTimers;
 static char *schedule_timer (TimerList *ntimer);
 
 static char *current_exec_timer = empty_string;
