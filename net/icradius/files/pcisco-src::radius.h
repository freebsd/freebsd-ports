--- src/radius.h.old	Tue Nov 21 23:35:27 2000
+++ src/radius.h	Tue Mar  6 18:16:58 2001
@@ -126,6 +126,13 @@
 
 #define PW_RADIUS_OPERATOR		100
 
+#define PW_CISCO_MAXIMUM_TIME		194
+#define PW_CISCO_DISCONNECT_CAUSE	195
+#define PW_CISCO_DATA_RATE		197
+#define PW_CISCO_XMIT_RATE		255
+
+
+
 #define PW_FALL_THROUGH			500
 #define PW_ADD_PORT_TO_IP_ADDRESS	501
 #define PW_EXEC_PROGRAM			502
