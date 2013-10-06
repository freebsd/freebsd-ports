--- utempter.c.orig	2007-02-19 12:14:08.000000000 +0000
+++ utempter.c
@@ -36,7 +36,7 @@
 
 #ifdef __GLIBC__
 # include <pty.h>
-#elif defined(__FreeBSD__)
+#elif defined(__FreeBSD__) || defined(__DragonFly__)
 # include <libutil.h>
 #else
 # error Unsupported platform
@@ -157,7 +157,7 @@ write_uwtmp_record(const char *user, con
 
 	(void) updwtmp(_PATH_WTMP, &ut);
 
-#elif defined(__FreeBSD__)
+#elif defined(__FreeBSD__) || defined(__DragonFly__)
 
 	ut.ut_time = tv.tv_sec;
 
