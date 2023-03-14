--- if_rereg.h.orig	2023-03-12 08:31:32 UTC
+++ if_rereg.h
@@ -1073,6 +1073,7 @@ enum bits {
 #define RT_DEVICEID_8162			0x8162		/* For RTL8168KB */
 #define RT_DEVICEID_8136			0x8136		/* For RTL8101E */
 #define RT_DEVICEID_8125			0x8125		/* For RTL8125 */
+#define RT_DEVICEID_3000			0x3000		/* For Killer E3000/E3100 with RTL8125 */
 
 /*
  * Accton PCI vendor ID
