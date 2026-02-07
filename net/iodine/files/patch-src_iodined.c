--- src/iodined.c.orig	2023-04-19 20:18:03 UTC
+++ src/iodined.c
@@ -2754,7 +2754,7 @@ main(int argc, char **argv)
 		do_pidfile(pidfile);
 
 #ifdef FREEBSD
-	tzsetwall();
+	tzset();
 #endif
 #ifndef WINDOWS32
 	openlog(__progname, LOG_NDELAY, LOG_DAEMON);
