--- grub-core/disk/geli.c.orig	2014-05-15 14:00:10.000000000 -0400
+++ grub-core/disk/geli.c	2014-09-26 10:18:53.325111693 -0400
@@ -430,6 +430,9 @@
   if (!grub_password_get (passphrase, MAX_PASSPHRASE))
     return grub_error (GRUB_ERR_BAD_ARGUMENT, "Passphrase not supplied");
 
+  /* Set the GELI passphrase to GRUB env, for passing to FreeBSD kernel */
+  grub_env_set ("gelipassphrase", passphrase);
+
   /* Calculate the PBKDF2 of the user supplied passphrase.  */
   if (grub_le_to_cpu32 (header.niter) != 0)
     {
