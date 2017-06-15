--- ../nginx-goodies-nginx-sticky-module-ng-08a395c66e42/ngx_http_sticky_misc.c.orig	2016-07-10 11:39:07.943834000 -0400
+++ ../nginx-goodies-nginx-sticky-module-ng-08a395c66e42/ngx_http_sticky_misc.c	2016-07-10 11:43:05.601078000 -0400
@@ -12,6 +12,14 @@
 
 #include "ngx_http_sticky_misc.h"
 
+#ifndef MD5_DIGEST_LENGTH
+  #define MD5_DIGEST_LENGTH	16
+#endif
+#ifndef MD5_CBLOCK
+  #define MD5_CBLOCK		64
+#endif
+
+
 #ifndef ngx_str_set
   #define ngx_str_set(str, text) (str)->len = sizeof(text) - 1; (str)->data = (u_char *) text
 #endif
