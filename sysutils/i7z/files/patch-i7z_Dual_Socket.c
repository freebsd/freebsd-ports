--- ./i7z_Dual_Socket.c.orig	2012-09-11 08:15:54.000000000 +0200
+++ ./i7z_Dual_Socket.c	2012-12-11 14:41:28.000000000 +0100
@@ -242,14 +242,14 @@
 
         if (socket_0.socket_num == 0)
         {
-            mvprintw (31, 0, "C0 = Processor running without halting");
-            mvprintw (32, 0, "C1 = Processor running with halts (States >C0 are power saver)");
-            mvprintw (33, 0, "C3 = Cores running with PLL turned off and core cache turned off");
-            mvprintw (34, 0, "C6 = Everything in C3 + core state saved to last level cache");
-            mvprintw (35, 0, "  Above values in table are in percentage over the last 1 sec");
-            mvprintw (36, 0, "[core-id] refers to core-id number in /proc/cpuinfo");
-            mvprintw (37, 0, "'Garbage Values' message printed when garbage values are read");
-            mvprintw (38, 0, "  Ctrl+C to exit");
+            mvprintw (3 + (socket_0.max_cpu+8)*2, 0, "C0 = Processor running without halting");
+            mvprintw (4 + (socket_0.max_cpu+8)*2, 0, "C1 = Processor running with halts (States >C0 are power saver)");
+            mvprintw (5 + (socket_0.max_cpu+8)*2, 0, "C3 = Cores running with PLL turned off and core cache turned off");
+            mvprintw (6 + (socket_0.max_cpu+8)*2, 0, "C6 = Everything in C3 + core state saved to last level cache");
+            mvprintw (7 + (socket_0.max_cpu+8)*2, 0, "  Above values in table are in percentage over the last 1 sec");
+            mvprintw (8 + (socket_0.max_cpu+8)*2, 0, "[core-id] refers to core-id number in /proc/cpuinfo");
+            mvprintw (9 + (socket_0.max_cpu+8)*2, 0, "'Garbage Values' message printed when garbage values are read");
+            mvprintw (10 + (socket_0.max_cpu+8)*2, 0, "  Ctrl+C to exit");
         }
 
         numCPUs = core_list_size_phy;
@@ -763,7 +763,7 @@
           		C3_time[socket_num], C6_time[socket_num], tvstart[socket_num], tvstop[socket_num], &max_observed_cpu_socket2);
         }else{*/
         socket_num=1;
-        printw_offset=14;
+        printw_offset=socket_0.max_cpu+8;
         print_i7z_socket(socket_1, printw_offset, PLATFORM_INFO_MSR,  PLATFORM_INFO_MSR_high, PLATFORM_INFO_MSR_low,
                          online_cpus, cpu_freq_cpuinfo, one_second_sleep, TURBO_MODE, HT_ON_str, &kk_2,
                          old_val_CORE[socket_num], old_val_REF[socket_num], old_val_C3[socket_num], old_val_C6[socket_num], old_val_C7[socket_num],
