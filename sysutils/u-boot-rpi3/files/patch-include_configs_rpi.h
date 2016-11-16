--- include/configs/rpi.h.orig	2016-11-14 16:27:11 UTC
+++ include/configs/rpi.h
@@ -104,11 +104,13 @@
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
 
