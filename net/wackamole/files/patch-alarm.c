--- alarm.c.orig	2014-05-06 16:24:44.652074671 -0700
+++ alarm.c	2014-05-06 16:26:49.173062394 -0700
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
