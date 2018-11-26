From c731cc3f2d72c7d41a9087c8eff46d3679659e20 Mon Sep 17 00:00:00 2001
From: Emmanuel Vadot <manu@freebsd.org>
Date: Fri, 23 Nov 2018 17:33:47 +0100
Subject: [PATCH] Revert "efi_loader: remove efi_exit_caches()"

This reverts commit 3170db63c41a2eda6ee6573353bb4de8c7c1b9d5.
---
 lib/efi_loader/efi_boottime.c | 28 ++++++++++++++++++++++++++++
 1 file changed, 28 insertions(+)

diff --git a/lib/efi_loader/efi_boottime.c b/lib/efi_loader/efi_boottime.c
index da978d2b34..54c597f042 100644
--- lib/efi_loader/efi_boottime.c
+++ lib/efi_loader/efi_boottime.c
@@ -26,6 +26,14 @@ LIST_HEAD(efi_obj_list);
 /* List of all events */
 LIST_HEAD(efi_events);
 
+/*
+ * If we're running on nasty systems (32bit ARM booting into non-EFI Linux)
+ * we need to do trickery with caches. Since we don't want to break the EFI
+ * aware boot path, only apply hacks when loading exiting directly (breaking
+ * direct Linux EFI booting along the way - oh well).
+ */
+static bool efi_is_direct_boot = true;
+
 #ifdef CONFIG_ARM
 /*
  * The "gd" pointer lives in a register on ARM and AArch64 that we declare
@@ -1678,6 +1686,8 @@ static efi_status_t EFIAPI efi_start_image(efi_handle_t image_handle,
 
 	EFI_ENTRY("%p, %p, %p", image_handle, exit_data_size, exit_data);
 
+	efi_is_direct_boot = false;
+
 	/* call the image! */
 	if (setjmp(&image_obj->exit_jmp)) {
 		/*
@@ -1785,6 +1795,21 @@ static efi_status_t EFIAPI efi_unload_image(efi_handle_t image_handle)
 	return EFI_EXIT(EFI_SUCCESS);
 }
 
+/**
+ * efi_exit_caches() - fix up caches for EFI payloads if necessary
+ */
+static void efi_exit_caches(void)
+{
+#if defined(CONFIG_ARM) && !defined(CONFIG_ARM64)
+	/*
+	 * Grub on 32bit ARM needs to have caches disabled before jumping into
+	 * a zImage, but does not know of all cache layers. Give it a hand.
+	 */
+	if (efi_is_direct_boot)
+		cleanup_before_linux();
+#endif
+}
+
 /**
  * efi_exit_boot_services() - stop all boot services
  * @image_handle: handle of the loaded image
@@ -1838,6 +1863,9 @@ static efi_status_t EFIAPI efi_exit_boot_services(efi_handle_t image_handle,
 
 	board_quiesce_devices();
 
+	/* Fix up caches for EFI payloads if necessary */
+	efi_exit_caches();
+
 	/* This stops all lingering devices */
 	bootm_disable_interrupts();
 
-- 
2.19.0

