--- src/filemanager/filemanager.c.orig	2021-01-10 11:50:16 UTC
+++ src/filemanager/filemanager.c
@@ -863,7 +863,7 @@ setup_mc (void)
         add_select_channel (mc_global.tty.subshell_pty, load_prompt, NULL);
 #endif /* !ENABLE_SUBSHELL */
 
-    if ((tty_baudrate () < 9600) || mc_global.tty.slow_terminal)
+    if ((tty_baudrate () > 0 && tty_baudrate () < 9600) || mc_global.tty.slow_terminal)
         verbose = FALSE;
 }
 
