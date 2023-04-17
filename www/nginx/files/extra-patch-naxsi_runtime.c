--- ../naxsi-29793dc/naxsi_src/naxsi_runtime.c.orig	2022-07-10 18:11:39.685243000 -0400
+++ ../naxsi-29793dc/naxsi_src/naxsi_runtime.c	2022-07-10 18:14:53.935554000 -0400
@@ -9,6 +9,11 @@
 #include "naxsi_macros.h"
 #include "naxsi_net.h"
 
+#if (NGX_PCRE2)
+#include <pcre2.h>
+#else
+#include <pcre.h>
+#endif
 /* used to store locations during the configuration time.
    then, accessed by the hashtable building feature during "init" time. */
 
@@ -181,7 +186,7 @@
 unsigned char*
 ngx_utf8_check(ngx_str_t* str);
 
-#if defined nginx_version && (nginx_version >= 1021005)
+#if (NGX_PCRE2)
 /*
  * variables to use pcre2
  */
