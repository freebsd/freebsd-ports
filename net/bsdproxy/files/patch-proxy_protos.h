diff -urN -x .svn ../../branches/vendor/bsdproxy/proxy_protos.h ./proxy_protos.h
--- ../../branches/vendor/bsdproxy/proxy_protos.h	2008-06-08 22:30:53.000000000 +0300
+++ ./proxy_protos.h	2008-06-08 22:55:52.000000000 +0300
@@ -52,7 +52,7 @@
 
   /* proxy_util.c */
 
-void  log_msg          ( struct mdata *md, char *fmt, ... );
+void  log_msg          ( struct mdata *md, const char *fmt, ... );
 void  print_stats      ( struct mdata * );
 float diff_timeval     ( struct timeval *t_start, struct timeval *t_finish );
 
