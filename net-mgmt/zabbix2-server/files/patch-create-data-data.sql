--- create/data/data.sql.orig	2011-08-04 09:48:23.785558036 -0500
+++ create/data/data.sql	2011-08-04 09:48:41.277736192 -0500
@@ -27,8 +27,8 @@
 -- Dumping data for table `scripts`
 --
 
-INSERT INTO scripts VALUES (1,'Ping','/bin/ping -c 3 {HOST.CONN}',2,0,0);
-INSERT INTO scripts VALUES (2,'Traceroute','/usr/bin/traceroute {HOST.CONN}',2,0,0);
+INSERT INTO scripts VALUES (1,'Ping','/sbin/ping -c 3 {HOST.CONN}',2,0,0);
+INSERT INTO scripts VALUES (2,'Traceroute','/usr/sbin/traceroute {HOST.CONN}',2,0,0);
 
 --
 -- Dumping data for table `users`
