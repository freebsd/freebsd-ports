--- grub-core/disk/geli.c.orig	2015-01-30 16:34:55 UTC
+++ grub-core/disk/geli.c
@@ -50,6 +50,7 @@
 #include <grub/misc.h>
 #include <grub/mm.h>
 #include <grub/dl.h>
+#include <grub/env.h>
 #include <grub/err.h>
 #include <grub/disk.h>
 #include <grub/crypto.h>
@@ -444,6 +445,9 @@ recover_key (grub_disk_t source, grub_cryptodisk_t dev
   grub_free (tmp);
   if (!grub_password_get (passphrase, MAX_PASSPHRASE))
     return grub_error (GRUB_ERR_BAD_ARGUMENT, "Passphrase not supplied");
+
+  /* Set the GELI passphrase to GRUB env, for passing to FreeBSD kernel */
+  grub_env_set ("gelipassphrase", passphrase);
 
   /* Calculate the PBKDF2 of the user supplied passphrase.  */
   if (grub_le_to_cpu32 (header.niter) != 0)
