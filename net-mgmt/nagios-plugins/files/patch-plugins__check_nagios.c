--- ./plugins/check_nagios.c.orig	2012-11-15 16:13:33.000000000 +0900
+++ ./plugins/check_nagios.c	2012-11-15 16:13:49.000000000 +0900
@@ -64,6 +64,7 @@
 	int procuid = 0;
 	int procpid = 0;
 	int procppid = 0;
+	int procjid = 0;
 	int procvsz = 0;
 	int procrss = 0;
 	float procpcpu = 0;
