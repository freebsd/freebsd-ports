diff --git a/grub-core/disk/efi/efidisk.c b/grub-core/disk/efi/efidisk.c
index 3b12c34..97f7456 100644
--- grub-core/disk/efi/efidisk.c
+++ grub-core/disk/efi/efidisk.c
@@ -862,9 +862,7 @@ grub_efidisk_get_device_name (grub_efi_handle_t *handle)
 	  if (! ctx.partition_name)
 	    {
 	      grub_disk_close (parent);
-	      if (is_cdrom)
-		return grub_strdup (device_name);
-	      return 0;
+              return grub_strdup (device_name);
 	    }
 
 	  dev_name = grub_xasprintf ("%s,%s", parent->name,
