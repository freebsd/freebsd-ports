--- libinstaller/syslinux.h.orig	2010-10-20 21:25:38.000000000 +0200
+++ libinstaller/syslinux.h	2010-11-16 15:03:24.279408609 +0100
@@ -18,12 +18,12 @@
 #include "setadv.h"
 
 /* The standard boot sector and ldlinux image */
-extern unsigned char syslinux_bootsect[];
+extern unsigned char *syslinux_bootsect;
 extern const unsigned int syslinux_bootsect_len;
 extern const int syslinux_bootsect_mtime;
 
-extern unsigned char syslinux_ldlinux[];
-extern const unsigned int syslinux_ldlinux_len;
+extern unsigned char *syslinux_ldlinux;
+extern unsigned int syslinux_ldlinux_len;
 extern const int syslinux_ldlinux_mtime;
 
 #define boot_sector	syslinux_bootsect
@@ -31,7 +31,7 @@
 #define boot_image	syslinux_ldlinux
 #define boot_image_len	syslinux_ldlinux_len
 
-extern unsigned char syslinux_mbr[];
+extern unsigned char *syslinux_mbr;
 extern const unsigned int syslinux_mbr_len;
 extern const int syslinux_mbr_mtime;
 
