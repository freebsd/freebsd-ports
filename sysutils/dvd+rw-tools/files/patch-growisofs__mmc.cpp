# Cannot append data to BD-R DL used more than 25gb
# https://bugs.freebsd.org/230493 via http://bugs.debian.org/615978
#
# growisofs error: close session failed when burning 25gb blu-ray disc
# https://bugs.freebsd.org/198991 via http://bugs.debian.org/713016 

--- growisofs_mmc.cpp.orig	2008-03-04 17:47:49 UTC
+++ growisofs_mmc.cpp
@@ -410,7 +410,7 @@ static unsigned int get_2k_capacity (Scsi_Command &cmd
 	    }
 
 	    nwa = 0;
-	    if (buf[7]&1 && !bdr_plus_pow)	// NWA_V
+	    if (buf[7]&1)	// NWA_V
 	    {	nwa  = buf[12]<<24;
 		nwa |= buf[13]<<16;
 		nwa |= buf[14]<<8;
@@ -755,6 +755,8 @@ static void bd_r_format (Scsi_Command &cmd)
 	exit (FATAL_START(errno));
 
     wait_for_unit (cmd);
+
+    bdr_plus_pow = 1;
 
     cmd[0] = 0x35;	// FLUSH CACHE
     cmd[9] = 0;
