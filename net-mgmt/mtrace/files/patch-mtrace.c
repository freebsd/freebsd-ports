--- mtrace.c.orig	Thu Sep 28 22:58:53 2006
+++ mtrace.c	Thu Sep 28 23:00:11 2006
@@ -1486,6 +1486,7 @@
     struct sockaddr_in recvaddr;
     struct tm *now;
     char timebuf[32];
+    time_t tr_sec;
     int socklen;
     int ipdatalen, iphdrlen, igmpdatalen;
     int len, recvlen;
@@ -1593,7 +1594,8 @@
 	    }
 	}
 
-	now = localtime(&tr.tv_sec);
+	tr_sec = tr.tv_sec;
+	now = localtime(&tr_sec);
 	strftime(timebuf, sizeof(timebuf) - 1, "%b %e %k:%M:%S", now);
 	printf("Mtrace %s at %s",
 		len == 0 ? "query" :
