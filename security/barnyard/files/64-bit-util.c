--- src/util.c	2004-03-06 17:30:15.000000000 -0500
+++ src/util.c	2007-08-12 00:14:52.000000000 -0400
@@ -514,7 +514,8 @@
 
 static char tmpbuf[256];
 
-int RenderTimeval(struct timeval *tv, char *timebuf, size_t len)
+// int RenderTimeval(struct timeval *tv, char *timebuf, size_t len)
+int RenderTimeval(struct pcap_timeval *tv, char *timebuf, size_t len)
 {
     struct tm *lt;
     time_t timet;
