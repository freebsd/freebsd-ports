--- src/main.c.orig	2018-03-01 16:24:07 UTC
+++ src/main.c
@@ -362,7 +362,7 @@ int received_dns = 0;
 int sr_auto_aliases=1;
 char* working_dir = 0;
 char* chroot_dir = 0;
-char* runtime_dir = "" RUN_DIR;
+char* runtime_dir = "/var/run/kamailio/";
 char* user=0;
 char* group=0;
 int uid = 0;
