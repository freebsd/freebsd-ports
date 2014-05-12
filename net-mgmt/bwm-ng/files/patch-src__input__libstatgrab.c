--- ./src/input/libstatgrab.c.orig	2007-02-28 02:05:56.000000000 +0000
+++ ./src/input/libstatgrab.c	2014-05-10 23:06:43.234799929 +0100
@@ -27,7 +27,8 @@
 /* do the actual work, get and print stats if verbose */
 void get_iface_stats_libstat (char verbose) {
     sg_network_io_stats *network_stats=NULL;
-    int num_network_stats,current_if_num=0,hidden_if=0;
+    size_t num_network_stats;
+    int current_if_num=0,hidden_if=0;
 	
 	t_iface_speed_stats stats; /* local struct, used to calc total values */
     t_iface_speed_stats tmp_if_stats;
@@ -61,7 +62,8 @@
 
 void get_iface_stats_libstatdisk (char verbose) {
    sg_disk_io_stats *disk_stats=NULL;
-   int num_disk_stats,current_if_num=0,hidden_if=0;
+   size_t num_disk_stats;
+   int current_if_num=0,hidden_if=0;
 
    t_iface_speed_stats stats; /* local struct, used to calc total values */
    t_iface_speed_stats tmp_if_stats;
