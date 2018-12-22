--- include/ntop_defines.h.orig	2018-12-21 18:58:17 UTC
+++ include/ntop_defines.h
@@ -416,7 +416,7 @@
 #define NTOPNG_NDPI_OS_PROTO_ID      (NDPI_LAST_IMPLEMENTED_PROTOCOL+NDPI_MAX_NUM_CUSTOM_PROTOCOLS-2)
 #define CONST_DEFAULT_HOME_NET       "192.168.1.0/24"
 #define CONST_OLD_DEFAULT_DATA_DIR   "/var/tmp/ntopng"
-#define CONST_DEFAULT_DATA_DIR       "/var/lib/ntopng"
+#define CONST_DEFAULT_DATA_DIR       "/var/db/ntopng"
 #define CONST_DEFAULT_MAX_UI_STRLEN  24
 #define CONST_DEFAULT_IS_AUTOLOGOUT_ENABLED               1
 #define CONST_DEFAULT_IS_IDLE_LOCAL_HOSTS_CACHE_ENABLED   1
