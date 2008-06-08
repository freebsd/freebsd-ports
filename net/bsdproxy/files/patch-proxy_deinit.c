diff -urN -x .svn ../../branches/vendor/bsdproxy/proxy_deinit.c ./proxy_deinit.c
--- ../../branches/vendor/bsdproxy/proxy_deinit.c	2008-06-08 22:30:53.000000000 +0300
+++ ./proxy_deinit.c	2008-06-08 22:35:09.000000000 +0300
@@ -21,7 +21,7 @@
 
   if ( md ) {
 
-    logmsg(md,"deinit_mdata(%p)",md);
+    log_msg(md,"deinit_mdata(%p)",md);
 
     if ( md->r ) {
 
