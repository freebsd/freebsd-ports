--- libfwupdplugin/fu-uefi-device.c.orig	2026-03-12 10:08:33 UTC
+++ libfwupdplugin/fu-uefi-device.c
@@ -281,7 +281,7 @@ fu_uefi_device_probe(FuDevice *device, GError **error)
 		return FALSE;
 	return fu_device_build_instance_id_full(device,
 						FU_DEVICE_INSTANCE_FLAG_QUIRKS,
-						NULL,
+						error,
 						"UEFI",
 						"GUID",
 						"NAME",
