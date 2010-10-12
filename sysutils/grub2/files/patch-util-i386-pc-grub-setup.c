--- util/i386/pc/grub-setup.c.orig	2010-03-06 12:51:37.000000000 -0800
+++ util/i386/pc/grub-setup.c	2010-10-10 02:56:55.000000000 -0700
@@ -38,7 +38,8 @@
 #include <grub/util/getroot.h>
 
 static const grub_gpt_part_type_t grub_gpt_partition_type_bios_boot = GRUB_GPT_PARTITION_TYPE_BIOS_BOOT;
-
+static const grub_gpt_part_type_t grub_gpt_partition_type_freebsd_boot = GRUB_GPT_PARTITION_TYPE_FREEBSD_BOOT;
+static const grub_gpt_part_type_t grub_gpt_partition_type_solaris_boot = GRUB_GPT_PARTITION_TYPE_SOLARIS_BOOT;
 #include <grub_setup_init.h>
 
 #include <stdio.h>
@@ -138,7 +139,9 @@
       struct grub_gpt_partentry *gptdata = p->data;
 
       /* If there's an embed region, it is in a dedicated partition.  */
-      if (! memcmp (&gptdata->type, &grub_gpt_partition_type_bios_boot, 16))
+      if (! memcmp (&gptdata->type, &grub_gpt_partition_type_bios_boot, 16) || 
+	      ! memcmp (&gptdata->type, &grub_gpt_partition_type_freebsd_boot, 16) ||
+		  ! memcmp (&gptdata->type, &grub_gpt_partition_type_solaris_boot, 16))
 	{
 	  embed_region.start = p->start;
 	  embed_region.end = p->start + p->len;
