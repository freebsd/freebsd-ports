--- src/filemanager/midnight.c.orig	2017-03-04 17:51:38 UTC
+++ src/filemanager/midnight.c
@@ -879,7 +879,7 @@ setup_mc (void)
         add_select_channel (mc_global.tty.subshell_pty, load_prompt, 0);
 #endif /* !ENABLE_SUBSHELL */
 
-    if ((tty_baudrate () < 9600) || mc_global.tty.slow_terminal)
+    if ((tty_baudrate () > 0 && tty_baudrate () < 9600) || mc_global.tty.slow_terminal)
         verbose = FALSE;
 }
 
