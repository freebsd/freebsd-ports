--- mod_log_spread.c.orig	Thu Aug 16 04:27:58 2001
+++ mod_log_spread.c	Wed May 11 06:55:14 2005
@@ -895,7 +895,7 @@
 static int spread_multicast_log_to_daemon(request_rec *r, char *group_name, int daemon_index, char *str, int len)
 {
     int sperror;
-    char *src;
+    const char *src;
     char tmpgrp[MAX_GROUP_NAME];
     char lchostname[1024];
     char *dst = lchostname;
