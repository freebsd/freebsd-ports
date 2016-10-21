--- include/configs/rpi.h.orig	2016-09-12 14:05:51 UTC
+++ include/configs/rpi.h
@@ -108,11 +108,13 @@
 #endif
 
 /* Console UART */
+/*
 #ifdef CONFIG_BCM2837
 #define CONFIG_BCM283X_MU_SERIAL
 #else
+*/
 #define CONFIG_PL01X_SERIAL
-#endif
+/* #endif */
 #define CONFIG_CONS_INDEX		0
 #define CONFIG_BAUDRATE			115200
 
