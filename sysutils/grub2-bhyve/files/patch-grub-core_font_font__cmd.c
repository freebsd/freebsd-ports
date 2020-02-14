--- grub-core/font/font_cmd.c.orig	2020-02-03 00:11:34 UTC
+++ grub-core/font/font_cmd.c
@@ -28,6 +28,9 @@ loadfont_command (grub_command_t cmd __attribute__ ((u
 		  int argc,
 		  char **args)
 {
+#if 1 /* BHYVE */
+  grub_puts_("Font loading disabled.");
+#else
   if (argc == 0)
     return grub_error (GRUB_ERR_BAD_ARGUMENT, N_("filename expected"));
 
@@ -38,6 +41,7 @@ loadfont_command (grub_command_t cmd __attribute__ ((u
 	  return grub_error (GRUB_ERR_BAD_FONT, "invalid font");
 	return grub_errno;
       }
+#endif
 
   return GRUB_ERR_NONE;
 }
