--- ./src/uprecords.c.orig	2009-01-01 15:46:00.000000000 -0800
+++ ./src/uprecords.c	2011-05-04 23:56:53.000000000 -0700
@@ -236,6 +236,9 @@
 			totalutime += u->utime;
 		}
 		
+		/* Prevents the downtime from showing as -x days, and the uptime as >100% */
+		totaldtime = -totaldtime;
+
 		print_entry(totalutime, "since", since, "up", 0, 0);
 		print_entry(totaldtime, "since", since, "down", 0, 0);
 		
