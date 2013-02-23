--- include/uams_def.h.orig	2007-09-07 13:10:51.000000000 +0000
+++ include/uams_def.h	2012-10-14 13:11:34.000000000 +0000
@@ -1,16 +0,0 @@
-#ifndef __UAM_DEFS_H_
-#define __UAM_DEFS_H_
-
-#define UAM_NOUSERAUTHENT 0x1
-#define UAM_CLEARTXTPASSWRD 0x2
-#define UAM_RANDNUMEXCHANGE 0x4
-#define UAM_2WAYRANDNUM 0x8
-#define UAM_DHCAST128 0x10
-#define UAM_CLIENTKRB 0x20
-#define UAM_DHX2 0x40
-#define UAM_RECON1 0x80
-
-int uam_string_to_bitmap(char * name);
-char * uam_bitmap_to_string(unsigned int bitmap);
-
-#endif
diff -Naur afpfs-ng-0.8.1.orig/include/utils.h afpfs-ng-0.8.1/include/utils.h
