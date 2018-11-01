--- src/main.c.orig	2018-08-22 09:38:44 UTC
+++ src/main.c
@@ -361,7 +361,7 @@ int received_dns = 0;
 int sr_auto_aliases=1;
 char* working_dir = 0;
 char* chroot_dir = 0;
-char* runtime_dir = "" RUN_DIR;
+char* runtime_dir = "/var/run/kamailio/";
 char* user=0;
 char* group=0;
 int uid = 0;
