--- modules/memcached.c.orig	2016-04-30 12:42:52 UTC
+++ modules/memcached.c
@@ -47,7 +47,7 @@
 #include <libmemcached/memcached_pool.h>
 #endif
 
-#include <crypt.h>
+/* #include <crypt.h> */
 
 int USE_MD5_SUM_KEYS = 1;
    
