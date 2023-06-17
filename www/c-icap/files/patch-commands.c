--- commands.c.orig	2021-09-14 10:21:46 UTC
+++ commands.c
@@ -233,7 +233,7 @@ void ci_command_schedule_on(const char *name, void *da
     sch.when = time;
     sch.data = data;
     if (ci_list_search(COMMANDS_QUEUE, &sch)) {
-        ci_debug_printf(7, "command %s already scheduled for execution on %ld, ignore\n", name, time);
+        ci_debug_printf(7, "command %s already scheduled for execution on %" PRId64 ", ignore\n", name, (uint64_t)time);
         return;
     }
     ci_thread_mutex_lock(&COMMANDS_MTX);
