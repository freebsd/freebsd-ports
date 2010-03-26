--- libssh/auth.c.orig	2010-03-16 02:34:17.000000000 +0800
+++ libssh/auth.c	2010-03-26 15:41:36.000000000 +0800
@@ -866,6 +866,8 @@
     char *privkey_file = NULL;
     int privkey_open = 0;
 
+    privkey = NULL;
+
     privkey_file = dir_expand_dup(session, it->data, 1);
     if (privkey_file == NULL) {
       continue;
