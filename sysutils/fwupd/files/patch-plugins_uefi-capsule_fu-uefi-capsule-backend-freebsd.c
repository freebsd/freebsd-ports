--- plugins/uefi-capsule/fu-uefi-capsule-backend-freebsd.c.orig	2026-03-12 10:08:33 UTC
+++ plugins/uefi-capsule/fu-uefi-capsule-backend-freebsd.c
@@ -7,6 +7,7 @@
 
 #include "config.h"
 
+#include <efivar.h>
 #include <fcntl.h>
 #include <sys/ioctl.h>
 #include <sys/types.h>
@@ -114,10 +115,23 @@ fu_uefi_capsule_backend_freebsd_coldplug(FuBackend *ba
 #ifdef HAVE_FREEBSD_ESRT
 	FuUefiCapsuleBackend *self = FU_UEFI_CAPSULE_BACKEND(backend);
 	const gchar *esrt_dev = "/dev/efi";
-	struct efi_get_table_ioc table = {.uuid = EFI_TABLE_ESRT};
+	struct efi_get_table_ioc table = {0};
+	efi_guid_t esrt_uuid = EFI_TABLE_ESRT;
 	g_autofd gint efi_fd = -1;
 	struct efi_esrt_entry_v1 *entries;
 	g_autofree struct efi_esrt_table *esrt = NULL;
+
+	/* must copy because of incompatible initializer (UUID vs. GUID) */
+	if (!fu_memcpy_safe((guint8 *)&table.uuid,
+			    sizeof(table.uuid),
+			    0,
+			    (const guint8 *)&esrt_uuid,
+			    sizeof(esrt_uuid),
+			    0,
+			    sizeof(esrt_uuid),
+			    error)) {
+		return FALSE;
+	}
 
 	efi_fd = g_open(esrt_dev, O_RDONLY, 0);
 	if (efi_fd < 0) {
