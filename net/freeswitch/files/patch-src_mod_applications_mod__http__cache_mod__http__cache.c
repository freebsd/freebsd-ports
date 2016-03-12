--- src/mod/applications/mod_http_cache/mod_http_cache.c.orig	2016-01-12 16:32:36 UTC
+++ src/mod/applications/mod_http_cache/mod_http_cache.c
@@ -37,6 +37,8 @@
 #include "aws.h"
 
 #include <stdlib.h>
+#include <string.h>
+char    *strndup(const char *, size_t) __malloc_like;
 
 /* 253 max domain size + '/' + NUL byte */
 #define DOMAIN_BUF_SIZE 255
