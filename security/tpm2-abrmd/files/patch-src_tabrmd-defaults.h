--- src/tabrmd-defaults.h.orig	2019-09-23 18:08:25 UTC
+++ src/tabrmd-defaults.h
@@ -17,7 +17,7 @@
 #define TABRMD_SESSIONS_MAX_DEFAULT 4
 #define TABRMD_SESSIONS_MAX 64
 #define TABRMD_TCTI_FILENAME_DEFAULT "libtss2-tcti-device.so.0"
-#define TABRMD_TCTI_CONF_DEFAULT NULL
+#define TABRMD_TCTI_CONF_DEFAULT "device:/dev/tpm"
 #define TABRMD_TRANSIENT_MAX_DEFAULT 27
 #define TABRMD_TRANSIENT_MAX 100
 
