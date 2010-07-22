--- utmp.c
+++ utmp.c
@@ -589,7 +589,7 @@
 struct utmp *u;
 {
   u->ut_type = DEAD_PROCESS;
-#if !defined(linux) || defined(EMPTY)
+#if (!defined(linux) || defined(EMPTY)) && !defined(__FreeBSD__)
   u->ut_exit.e_termination = 0;
   u->ut_exit.e_exit = 0;
 #endif
@@ -728,7 +728,7 @@
 {
   strncpy(u->ut_line, line, sizeof(u->ut_line));
   strncpy(u->ut_name, user, sizeof(u->ut_name));
-  (void)time((time_t *)&u->ut_time);
+  u->ut_time = time(NULL);
 }
 
 static slot_t
