--- top_three.c	Fri May 28 23:23:33 2004
+++ top_three.c	Mon Jul 26 13:26:18 2004
@@ -307,11 +307,13 @@
     process->user_time = user_time;
     process->kernel_time = kernel_time;
 
+#if defined(LINUX)
     /* set it to zero for niced processes */
     if(show_nice_processes==0 && nice_val > 1) {
         process->user_time = 0;
         process->kernel_time = 0;
     }
+#endif
 
     return 0;
 }
