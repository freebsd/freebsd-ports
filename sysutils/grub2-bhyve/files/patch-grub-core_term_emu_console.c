--- grub-core/term/emu/console.c.orig	2015-05-26 09:58:09 UTC
+++ grub-core/term/emu/console.c
@@ -260,7 +260,7 @@ grub_ncurses_init (struct grub_term_outp
 
   if (g_cdev != NULL) {
     /* Open user-supplied console device. */
-    fd = open (g_cdev, O_RDWR);
+    fd = open (g_cdev, O_RDWR | O_NONBLOCK);
     if (fd < 0)
       return (GRUB_ERR_UNKNOWN_DEVICE);
 
