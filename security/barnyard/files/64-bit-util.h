--- src/util.h	2004-03-06 19:23:50.000000000 -0500
+++ src/util.h	2007-08-11 23:23:46.000000000 -0400
@@ -39,7 +39,8 @@
 void ClearDumpBuf();
 void GoDaemon();
 size_t RenderTimestamp(time_t timet, char *timebuf, size_t len);
-int RenderTimeval(struct timeval *tv, char *timebuf, size_t len);
+// int RenderTimeval(struct timeval *tv, char *timebuf, size_t len);
+int RenderTimeval(struct pcap_timeval *tv, char *timebuf, size_t len);
 int CreatePidFile(char *filename);
 int String2Long(char *string, long *result);
 int String2ULong(char *string, unsigned long *result);
