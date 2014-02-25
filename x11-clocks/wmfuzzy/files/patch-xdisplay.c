--- xdisplay.c.orig	2004-11-23 21:32:48.000000000 +0000
+++ xdisplay.c
@@ -383,7 +383,7 @@ void display_main_loop(void)
       x_handle_event(&event);
     }
 
-    usleep(100);
+    sleep(1);
   }
 }
 
