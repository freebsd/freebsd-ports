--- src/nrpe.c.orig	2007-12-27 05:55:05.000000000 +1030
+++ src/nrpe.c	2008-02-20 19:19:03.000000000 +1030
@@ -1458,8 +1458,10 @@
 		                }while(bytes_read==-1 && errno==EINTR);
 		        }
 
-		if(bytes_read==-1 && output!=NULL)
-			strcpy(output,"");
+			if(bytes_read==-1)
+				*output='\0';
+			else
+				output[bytes_read]='\0';
 
 		/* if there was a critical return code and no output AND the command time exceeded the timeout thresholds, assume a timeout */
 		if(result==STATE_CRITICAL && bytes_read==-1 && (end_time-start_time)>=timeout){
