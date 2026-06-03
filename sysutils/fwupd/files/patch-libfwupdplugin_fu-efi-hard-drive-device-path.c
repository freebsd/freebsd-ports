--- libfwupdplugin/fu-efi-hard-drive-device-path.c.orig	2026-03-12 10:08:33 UTC
+++ libfwupdplugin/fu-efi-hard-drive-device-path.c
@@ -379,8 +379,10 @@ fu_efi_hard_drive_device_path_new_from_volume(FuVolume
 				    "partition UUID required");
 		return NULL;
 	}
+	/* FreeBSD uses "efi" partition kind for ESP */
 	if (g_strcmp0(partition_kind, FU_VOLUME_KIND_ESP) == 0 ||
-	    g_strcmp0(partition_kind, FU_VOLUME_KIND_BDP) == 0) {
+	    g_strcmp0(partition_kind, FU_VOLUME_KIND_BDP) == 0 ||
+	    g_strcmp0(partition_kind, "efi") == 0) {
 		self->partition_format =
 		    FU_EFI_HARD_DRIVE_DEVICE_PATH_PARTITION_FORMAT_GUID_PARTITION_TABLE;
 		self->signature_type = FU_EFI_HARD_DRIVE_DEVICE_PATH_SIGNATURE_TYPE_GUID;
