--- lib/efi_loader/efi_boottime.c.orig	2019-04-16 17:03:46 UTC
+++ lib/efi_loader/efi_boottime.c
@@ -1781,7 +1781,7 @@ efi_status_t EFIAPI efi_start_image(efi_handle_t image
 
 	EFI_ENTRY("%p, %p, %p", image_handle, exit_data_size, exit_data);
 
-	efi_is_direct_boot = false;
+	efi_is_direct_boot = true;
 
 	/* call the image! */
 	if (setjmp(&image_obj->exit_jmp)) {
