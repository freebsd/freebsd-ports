--- growisofs_mmc.cpp.orig	2008-03-04 17:47:49 UTC
+++ growisofs_mmc.cpp
@@ -756,6 +756,8 @@ static void bd_r_format (Scsi_Command &c
 
     wait_for_unit (cmd);
 
+    bdr_plus_pow = 1;
+
     cmd[0] = 0x35;	// FLUSH CACHE
     cmd[9] = 0;
     cmd.transport();
