
$FreeBSD$

--- daemonize.c
+++ daemonize.c
@@ -198,7 +198,7 @@
 	}
 	
 	if (log_stderr==0)
-		openlog(name, LOG_PID|LOG_CONS, log_facility);
+		openlog(name, LOG_PID, log_facility);
 		/* LOG_CONS, LOG_PERRROR ? */
 
 	return  0;
