diff -urN -x .svn ../../branches/vendor/bsdproxy/proxy_util.c ./proxy_util.c
--- ../../branches/vendor/bsdproxy/proxy_util.c	2008-06-08 22:30:53.000000000 +0300
+++ ./proxy_util.c	2008-06-08 23:00:09.000000000 +0300
@@ -16,7 +16,7 @@
 */
 
 void
-log_msg ( struct mdata *md, char *fmt, ... )
+log_msg ( struct mdata *md, const char *fmt, ... )
 {
   va_list   ap;
   char      bt[256];
