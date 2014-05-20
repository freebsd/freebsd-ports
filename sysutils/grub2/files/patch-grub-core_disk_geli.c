--- grub-core/disk/geli.c.orig	2014-05-15 14:00:10.000000000 -0400
+++ grub-core/disk/geli.c	2014-05-20 14:46:07.604565349 -0400
@@ -225,7 +225,7 @@
 
   /* Look for GELI magic sequence.  */
   if (grub_memcmp (header->magic, GELI_MAGIC, sizeof (GELI_MAGIC))
-      || grub_le_to_cpu32 (header->version) > 5
+      || grub_le_to_cpu32 (header->version) > 7
       || grub_le_to_cpu32 (header->version) < 1)
     grub_util_error ("%s", _("wrong ELI magic or version"));
 
@@ -265,7 +265,7 @@
 
   /* Look for GELI magic sequence.  */
   if (grub_memcmp (header.magic, GELI_MAGIC, sizeof (GELI_MAGIC))
-      || grub_le_to_cpu32 (header.version) > 5
+      || grub_le_to_cpu32 (header.version) > 7
       || grub_le_to_cpu32 (header.version) < 1)
     {
       grub_dprintf ("geli", "wrong magic %02x\n", header.magic[0]);
