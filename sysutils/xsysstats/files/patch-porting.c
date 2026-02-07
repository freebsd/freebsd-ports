--- porting.c.orig	2000-05-30 06:50:24 UTC
+++ porting.c
@@ -26,6 +26,9 @@ int rstat(char *host, struct statstime *stats)
 
 #ifdef USE_NEW_RSTAT
 #include <rpc/rpc.h>
+
+int open_host(struct Host_Info *host);
+
 int 
 rstat_local(struct Host_Info *host, struct statstime *statval)
 {
