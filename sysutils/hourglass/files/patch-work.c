--- src/work.c.orig	Tue Jan 23 04:28:43 2007
+++ src/work.c	Tue Jan 23 05:09:28 2007
@@ -176,7 +176,7 @@
 
 void *monitor_thrd_func (void *arg)
 {
-  int id = (int)arg;
+  int id = (int)(intptr_t)arg;
 
   assert (thrd_data[id].s_time != -1);
 
@@ -202,7 +202,7 @@
 
 void *thrd_func (void *arg)
 {
-  int id = (int)arg;
+  int id = (int)(intptr_t )arg;
 
   set_priority (thrd_data[id].pri);
 
