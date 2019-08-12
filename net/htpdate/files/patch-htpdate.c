--- htpdate.c.orig	2019-08-12 22:48:19 UTC
+++ htpdate.c
@@ -14,11 +14,11 @@
 	Debug mode (shows raw timestamps, round trip time (RTT) and
 	time difference):
 
-	~# htpdate -d www.linux.org www.freebsd.org
+	~# htpdate -d www.example.com
 
 	Adjust time smoothly:
 
-	~# htpdate -a www.linux.org www.freebsd.org
+	~# htpdate -a www.example.com
 
 	...see man page for more details
 
