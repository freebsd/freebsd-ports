--- netmap/netmap.c.orig	Sun Dec 15 14:54:26 2002
+++ netmap/netmap.c	Sun Dec 15 14:54:26 2002
@@ -32,7 +32,7 @@
 
 int count_invalid_hosts(const string& fname) 
 {
-    Infile inf(fname, ios::bin | ios::in);
+    Infile inf(fname, ios::binary | ios::in);
 
     int invalid_hosts = 0;
     int invalid_left = 0;
@@ -60,7 +60,7 @@
     const int num_invalid_hosts =
 	(keep_reading?count_invalid_hosts(fname):0);
     
-    Infile inf(fname, ios::bin | ios::in);
+    Infile inf(fname, ios::binary | ios::in);
 
     int mark_first = 1;
     string prev_addr = inv_ip;
