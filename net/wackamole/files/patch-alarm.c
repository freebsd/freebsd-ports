--- alarm.c.orig	2005-03-30 19:56:58 UTC
+++ alarm.c
@@ -93,7 +93,7 @@ void wack_alarm( int32 mask, char *message, ...)
 	  timestamp[length] = ' ';
 #ifdef HAVE_SYSLOG_H
 	  if(syslog_flag)
-	    syslog(LOG_NOTICE, timestamp);
+	    syslog(LOG_NOTICE, "%s", timestamp);
 	  else
 #endif
 	    fwrite(timestamp, length+1, sizeof(char), stdout);
@@ -105,7 +105,7 @@ void wack_alarm( int32 mask, char *message, ...)
 	int len = strlen(message)+100;
 	s = malloc(len);/*estimation*/
 	vsnprintf(s,len,message, ap);
-	syslog(LOG_NOTICE, s);
+	syslog(LOG_NOTICE, "%s", s);
 	free(s);
       }
       else 
