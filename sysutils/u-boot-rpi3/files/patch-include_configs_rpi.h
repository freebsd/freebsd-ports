--- include/configs/rpi.h.orig	2017-01-09 16:57:05 UTC
+++ include/configs/rpi.h
@@ -99,11 +99,13 @@
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
 
