--- output.c.orig	Fri Aug  1 06:34:16 2003
+++ output.c	Fri Aug  1 06:33:29 2003
@@ -40,7 +40,7 @@
 	vsnprintf(buf, sizeof(buf), fmt, v);
 	//fprintf(stderr,"[DEBUG %d] %s",getpid(),buf);
 	log(LOG_DEBUG,"[DEBUG %d] %s",getpid(),buf);
-	va_end(fmt);
+	va_end(v);
     }
 }
 
@@ -57,7 +57,7 @@
 	openlog(PROGNAME, LOG_PID , config_log_facility);
 	syslog(config_log_facility | level, "%s", buf);
 	//closelog();
-	va_end(fmt);
+	va_end(v);
     }
 }
 
