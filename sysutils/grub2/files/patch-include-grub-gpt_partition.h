--- include/grub/gpt_partition.h.orig	2010-03-06 12:51:37.000000000 -0800
+++ include/grub/gpt_partition.h	2010-10-10 02:57:26.000000000 -0700
@@ -40,6 +40,17 @@
     { 0x74, 0x4e, 0x65, 0x65, 0x64, 0x45, 0x46, 0x49 } \
   }
 
+#define GRUB_GPT_PARTITION_TYPE_FREEBSD_BOOT \
+  { grub_cpu_to_le32 (0x83BD6B9D), grub_cpu_to_le16 (0x7F41), grub_cpu_to_le16 (0x11DC), \
+    { 0xBE, 0x0B, 0x00, 0x15, 0x60, 0xB8, 0x4F, 0x0F } \
+  }
+  
+#define GRUB_GPT_PARTITION_TYPE_SOLARIS_BOOT \
+  { grub_cpu_to_le32 (0x6A82CB45), grub_cpu_to_le16 (0x1DD2), grub_cpu_to_le16 (0x11B2), \
+    { 0x99, 0xA6, 0x08, 0x00, 0x20, 0x73, 0x66, 0x31 } \
+  }
+
+
 struct grub_gpt_header
 {
   grub_uint8_t magic[8];
