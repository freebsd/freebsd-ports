--- deamoninit.c.orig	Wed Oct 31 10:19:57 2001
+++ deamoninit.c	Wed Oct 31 10:22:35 2001
@@ -113,13 +113,13 @@
   logging(2, 1, 0, 0, 1, "[ERROR] : Segfault bugtrace started at address: 0x%.8X\n", &ptr);
   logging(1, 1, 0, 0, 1, "Running as pid: %d, with uid: %d, recieving status: %d\n", 
 	  &sig->si_pid, &sig->si_uid, &sig->si_status);
-  logging(1, 1, 0, 0, 1, "Consuming %d User time, and %d System time\n", 
-	  &sig->si_utime , &sig->si_stime);
+  /* logging(1, 1, 0, 0, 1, "Consuming %d User time, and %d System time\n", 
+	  &sig->si_utime , &sig->si_stime); */
   logging(1, 1, 0, 0, 1, "Recovering from error code: %d\n", &sig->si_errno);
   logging(1, 1, 0, 0, 1, "Caused at address: 0x%.8X\n", &sig->si_addr);
-  logging(1, 1, 0, 0, 1, "While mengeling with fd: %d\n", &sig->si_fd);
+  /* logging(1, 1, 0, 0, 1, "While mengeling with fd: %d\n", &sig->si_fd); */
   /* hope this 'si_band' can be used here.. */
-  logging(1, 1, 0, 0, 1, "(%score dumped)\n", WCOREDUMP(&sig->si_band) ?"" : "no ");
+  /* logging(1, 1, 0, 0, 1, "(%score dumped)\n", WCOREDUMP(&sig->si_band) ?"" : "no "); */
   /*logging(1, 1, 0, 0, 1, "");*/
 
   /* hmmm should be a check here, about the syslog, 
