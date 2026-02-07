--- icmpmonitor.c.orig	Fri Jun  7 00:05:24 2002
+++ icmpmonitor.c	Fri Jun  7 00:05:11 2002
@@ -160,7 +160,7 @@
 /* protos */
 static void logopen(void);
 static void logclose(void);
-static void log(int type, char *format, ...);
+static void log(int type, char *format, ...) __printflike(2, 3);
 static int  gethostaddr(const char *name);
 static void read_hosts(const char *cfg_file_name);
 static void init_hosts(void);
@@ -698,7 +698,7 @@
 # endif
 #endif
 #if HAVE_SYSLOG            
-        syslog(type,buffer);
+        syslog(type,"%s",buffer);
 #endif
     } else
     {
