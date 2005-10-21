--- utmp.c.orig	Mon Sep  8 16:27:17 2003
+++ utmp.c	Wed Oct 19 14:58:40 2005
@@ -726,9 +728,12 @@
 char *line, *user;
 int pid;
 {
+  time_t temp;
+
   strncpy(u->ut_line, line, sizeof(u->ut_line));
   strncpy(u->ut_name, user, sizeof(u->ut_name));
-  (void)time((time_t *)&u->ut_time);
+  (void)time(&temp);
+  u->ut_time = temp;
 }
 
 static slot_t

