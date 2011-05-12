--- alarm.c.orig	2011-05-12 02:48:08.000000000 +0200
+++ alarm.c	2011-05-12 02:48:40.000000000 +0200
@@ -93,7 +93,7 @@
 	  timestamp[length] = ' ';
 #ifdef HAVE_SYSLOG_H
 	  if(syslog_flag)
-	    syslog(LOG_NOTICE, timestamp);
+	    syslog(LOG_NOTICE, "%s", timestamp);
 	  else
 #endif
 	    fwrite(timestamp, length+1, sizeof(char), stdout);
@@ -105,7 +105,7 @@
 	int len = strlen(message)+100;
 	s = malloc(len);/*estimation*/
 	vsnprintf(s,len,message, ap);
-	syslog(LOG_NOTICE, s);
+	syslog(LOG_NOTICE, "%s", s);
 	free(s);
       }
       else 
