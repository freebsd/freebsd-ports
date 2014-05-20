--- grub-core/disk/geli.c.orig	2014-05-20 14:18:46.333972233 -0400
+++ grub-core/disk/geli.c	2014-05-20 14:19:12.973970142 -0400
@@ -265,7 +265,7 @@
 
   /* Look for GELI magic sequence.  */
   if (grub_memcmp (header.magic, GELI_MAGIC, sizeof (GELI_MAGIC))
-      || grub_le_to_cpu32 (header.version) > 5
+      || grub_le_to_cpu32 (header.version) > 7
       || grub_le_to_cpu32 (header.version) < 1)
     {
       grub_dprintf ("geli", "wrong magic %02x\n", header.magic[0]);
