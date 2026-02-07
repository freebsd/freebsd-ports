--- src/usr.bin/make/main.c.orig	2020-08-29 04:02:38 UTC
+++ src/usr.bin/make/main.c
@@ -191,6 +191,8 @@ char *makeDependfile;
 pid_t myPid;
 int makelevel;
 
+FILE *debug_file;
+
 Boolean forceJobs = FALSE;
 
 extern Lst parseIncPath;
