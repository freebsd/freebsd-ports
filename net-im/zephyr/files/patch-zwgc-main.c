--- zwgc/main.c.orig	2009-12-20 01:29:41.000000000 +0000
+++ zwgc/main.c	2009-12-20 01:32:34.000000000 +0000
@@ -396,9 +396,8 @@
 void
 notice_handler(ZNotice_t *notice)
 {
-#ifndef HAVE_ARES
+    int error;
     char node[MAXDNAME];
-#endif
 
 #if defined(CMU_ZWGCPLUS)
     list_add_notice(notice);
@@ -415,9 +414,11 @@
                      notice_callback, notice);
     
 #else
-    getnameinfo((const struct sockaddr *)&(notice->z_sender_sockaddr),
+    error = getnameinfo((const struct sockaddr *)&(notice->z_sender_sockaddr),
                 sizeof(notice->z_sender_sockaddr),
                 node, sizeof(node), NULL, 0, 0);
+    if (error != 0)
+        snprintf(node, MAXDNAME, "?");
     
     process_notice(notice, node);
 #ifdef CMU_ZWGCPLUS
