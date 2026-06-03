--- plugins/uefi-capsule/fu-uefi-common.c.orig	2026-03-12 10:08:33 UTC
+++ plugins/uefi-capsule/fu-uefi-common.c
@@ -40,6 +40,12 @@ fu_uefi_bootmgr_get_suffix(FuPathStore *pstore, GError
 	if (sysfsefidir == NULL)
 		return NULL;
 	firmware_bits = fu_uefi_read_file_as_uint64(sysfsefidir, "fw_platform_size");
+#if defined(__FreeBSD__)
+	/* no means to determine this on FreeBSD? assume it matches the application when unambiguous */
+	if (firmware_bits == 0 && sizeof(suffixes)/sizeof(suffixes[0]) == 2) {
+		return suffixes[0].arch;
+	}
+#endif
 	if (firmware_bits == 0) {
 		g_set_error(error,
 			    FWUPD_ERROR,
