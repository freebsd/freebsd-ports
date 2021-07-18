--- csync2.h.orig	2013-05-02 12:58:14 UTC
+++ csync2.h
@@ -80,7 +80,7 @@ extern int csync_perm(const char *filena
 
 extern void csync_printtime();
 extern void csync_printtotaltime();
-extern void csync_fatal(const char *fmt, ...);
+extern void csync_fatal(const char *fmt, ...) __dead2;
 extern void csync_debug(int lv, const char *fmt, ...);
 
 #define csync_debug_ping(N) \
