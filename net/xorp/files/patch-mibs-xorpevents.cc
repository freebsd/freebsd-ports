--- mibs/xorpevents.cc-orig	2011-12-27 00:35:22.000000000 +0000
+++ mibs/xorpevents.cc	2011-12-27 00:36:01.000000000 +0000
@@ -55,7 +55,7 @@
 {
     SnmpEventLoop& e = SnmpEventLoop::the_instance();
     DEBUGMSGTL((e._log_name, "run all xorp timers\n"));
-    DEBUGMSGTL((e._log_name, "# of timers: %d\n", e.timer_list().size()));
+    DEBUGMSGTL((e._log_name, "# of timers: %zd\n", e.timer_list().size()));
     e.timer_list().run();
     SnmpEventLoop::AlarmMap::iterator p;
     for (p = e._pending_alarms.begin(); p != e._pending_alarms.end(); ++p) {
