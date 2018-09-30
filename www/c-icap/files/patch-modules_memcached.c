--- modules/memcached.c.orig	2017-10-21 06:57:48 UTC
+++ modules/memcached.c
@@ -47,7 +47,7 @@
 #include <libmemcached/memcached_pool.h>
 #endif
 
-#include <crypt.h>
+/* #include <crypt.h> */
 
 int USE_MD5_SUM_KEYS = 1;
 
