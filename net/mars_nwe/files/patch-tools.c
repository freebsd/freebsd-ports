--- ../work/mars_nwe/tools.c	Mon Jul  2 14:41:36 2007
+++ tools.c	Mon Jul  2 14:46:39 2007
@@ -51,7 +51,7 @@
 int    act_connection=0;  /* which connection (nwconn, nwbind) */
 time_t act_time=0L;       /* actual time */
 
-static FILE *logfile=NULL;
+FILE *logfile=NULL;
 static int   use_syslog=0; /* 1 = use syslog for all loggings
                             * 2 = only for errors
                             */
