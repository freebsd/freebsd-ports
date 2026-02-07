--- grub-core/commands/iorw.c.orig	2015-08-31 22:42:56 UTC
+++ grub-core/commands/iorw.c
@@ -45,6 +45,9 @@ grub_cmd_read (grub_extcmd_context_t ctxt, int argc, c
 
   if (argc != 1)
     return grub_error (GRUB_ERR_BAD_ARGUMENT, N_("one argument expected"));
+#if 1 /* BHYVE */
+  grub_puts_("Reading host IO ports disabled.");
+#else
 
   addr = grub_strtoul (argv[0], 0, 0);
   switch (ctxt->extcmd->cmd->name[sizeof ("in") - 1])
@@ -70,6 +73,7 @@ grub_cmd_read (grub_extcmd_context_t ctxt, int argc, c
     }
   else
     grub_printf ("0x%x\n", value);
+#endif
 
   return 0;
 }
@@ -84,6 +88,10 @@ grub_cmd_write (grub_command_t cmd, int argc, char **a
   if (argc != 2 && argc != 3)
     return grub_error (GRUB_ERR_BAD_ARGUMENT, N_("two arguments expected"));
 
+#if 1 /* BHYVE */
+  grub_puts_("Writing host IO ports disabled.");
+#else
+
   addr = grub_strtoul (argv[0], 0, 0);
   value = grub_strtoul (argv[1], 0, 0);
   if (argc == 3)
@@ -112,6 +120,7 @@ grub_cmd_write (grub_command_t cmd, int argc, char **a
 	grub_outb (value, addr);
       break;
     }
+#endif
 
   return 0;
 }
