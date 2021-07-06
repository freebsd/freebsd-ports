--- include/grub/efiemu/runtime.h.orig	2021-07-05 10:59:57.352037000 +0000
+++ include/grub/efiemu/runtime.h	2021-07-05 11:02:38.126967000 +0000
@@ -29,7 +29,7 @@
 
 struct efi_variable
 {
-  grub_efi_guid_t guid;
+  grub_efi_packed_guid_t guid;
   grub_uint32_t namelen;
   grub_uint32_t size;
   grub_efi_uint32_t attributes;
