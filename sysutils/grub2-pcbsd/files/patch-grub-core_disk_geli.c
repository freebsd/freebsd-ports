--- grub-core/disk/geli.c.orig	2014-05-15 14:00:10.000000000 -0400
+++ grub-core/disk/geli.c	2014-09-26 10:18:53.325111693 -0400
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
@@ -430,6 +430,9 @@
   if (!grub_password_get (passphrase, MAX_PASSPHRASE))
     return grub_error (GRUB_ERR_BAD_ARGUMENT, "Passphrase not supplied");
 
+  /* Set the GELI passphrase to GRUB env, for passing to FreeBSD kernel */
+  grub_env_set ("gelipassphrase", passphrase);
+
   /* Calculate the PBKDF2 of the user supplied passphrase.  */
   if (grub_le_to_cpu32 (header.niter) != 0)
     {
