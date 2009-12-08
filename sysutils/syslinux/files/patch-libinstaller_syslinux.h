--- libinstaller/syslinux.h.orig	2009-10-06 02:06:06.000000000 +0400
+++ libinstaller/syslinux.h	2009-12-04 10:09:04.000000000 +0300
@@ -17,15 +17,15 @@
 #include "advconst.h"
 
 /* The standard boot sector and ldlinux image */
-extern unsigned char syslinux_bootsect[];
+extern unsigned char *syslinux_bootsect;
 extern unsigned int syslinux_bootsect_len;
 extern int syslinux_bootsect_mtime;
 
-extern unsigned char syslinux_ldlinux[];
+extern unsigned char *syslinux_ldlinux;
 extern unsigned int syslinux_ldlinux_len;
 extern int syslinux_ldlinux_mtime;
 
-extern unsigned char syslinux_mbr[];
+extern unsigned char *syslinux_mbr;
 extern unsigned int syslinux_mbr_len;
 extern int syslinux_mbr_mtime;
 
