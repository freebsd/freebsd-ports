--- ./src/capture.c.orig	Sun Apr  6 10:45:41 2003
+++ ./src/capture.c	Sat Apr 29 11:48:08 2006
@@ -527,7 +527,16 @@
   this_time.tv_usec = phdr.ts.tv_usec;
 
   diff = substract_times (this_time, last_time);
-  ms_to_next = diff.tv_sec * 1000 + diff.tv_usec / 1000;
+
+  if (pref.zero_delay)
+    {
+      ms_to_next = 0;
+    }
+  else
+    {
+      ms_to_next = diff.tv_sec * 1000 + diff.tv_usec / 1000;
+    }
+
 
   last_time = this_time;
 
