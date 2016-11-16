--- include/efi_api.h.orig	2016-11-14 16:27:11 UTC
+++ include/efi_api.h
@@ -268,6 +268,18 @@ struct efi_device_path {
 	u16 length;
 };
 
+struct efi_mac_addr {
+	u8 addr[32];
+};
+
+#define DEVICE_PATH_TYPE_MESSAGING_DEVICE	0x03
+struct efi_device_path_mac_addr {
+	struct efi_device_path dp;
+	struct efi_mac_addr mac;
+	u8 if_type;
+};
+
+#  define DEVICE_PATH_SUB_TYPE_MSG_MAC_ADDR	0x0b
 #define DEVICE_PATH_TYPE_MEDIA_DEVICE		0x04
 #  define DEVICE_PATH_SUB_TYPE_FILE_PATH	0x04
 
