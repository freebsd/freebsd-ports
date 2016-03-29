--- libfdcore/sctp.c.orig	2013-09-14 10:09:01 UTC
+++ libfdcore/sctp.c
@@ -575,7 +575,7 @@ static int fd_setsockopt_prebind(int sk)
 		
 		struct sctp_event event;
 		
-		for (i = 0; i < (sizeof(events_I_want) / sizeof(events_I_want[0]) - 1; i++) {
+		for (i = 0; i < (sizeof(events_I_want) / sizeof(events_I_want[0]) - 1); i++) {
 			memset(&event, 0, sizeof(event));
 			event.se_type = events_I_want[i];
 			event.se_on = 1;
