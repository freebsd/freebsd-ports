--- gdb-5.3/gdb/remote-palmos.c.ORIG	2007-10-17 11:46:12.000000000 -0400
+++ gdb-5.3/gdb/remote-palmos.c	2007-10-17 11:46:44.000000000 -0400
@@ -128,13 +128,6 @@
 
 extern struct target_ops palmos_ops, pilot_ops;	/* Forward decl */
 
-/* This was 5 seconds, which is a long time to sit and wait.
-   Unless this is going though some terminal server or multiplexer or
-   other form of hairy serial connection, I would think 2 seconds would
-   be plenty.  */
-
-static int remote_timeout = 2;
-
 static CORE_ADDR text_addr=0, data_addr=0, bss_addr=0;
 static CORE_ADDR save_ssp, save_usp;
 static enum target_signal wbreakpoint_signo;
