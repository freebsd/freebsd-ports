--- ./nshow.c.orig	Thu Jun 21 03:21:35 2001
+++ ./nshow.c	Sun Sep 28 21:25:05 2003
@@ -217,14 +217,9 @@
         memset(line, SC8, maxx + 1);  /* clear dividing line */
         WndPutsn(0, 5, maxx, cm[CM_DTXT] | F_ALTERNATE, line);
         WndWriteStr(2, 0, cm[CM_NINF], tmpbuf);
-        if (SW->showaddr)
+        if (dv_running())
         {
-            sprintf(line, "%s", show_address(&CurArea.addr));
-            WndWriteStr(3, 5, cm[CM_NINF], line);
-            if (dv_running())
-            {
-                WndWriteStr(maxx - 7, 5, cm[CM_DTXT], "DV");
-            }
+            WndWriteStr(maxx - 7, 5, cm[CM_DTXT], "DV");
         }
         if (SW->usemouse)
         {
@@ -531,6 +526,11 @@
     }
 #endif
 
+    if (SW->showaddr)
+    {
+        sprintf(line, "%s", show_address(&CurArea.addr));
+        WndWriteStr(3, 5, cm[CM_NINF], line);
+    }
     if (SW->showtime)
     {
         WndPrintf(40, 5, cm[CM_HTXT], " %s ", itime(time(NULL)));
