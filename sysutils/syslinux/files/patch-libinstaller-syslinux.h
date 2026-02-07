--- libinstaller/syslinux.h.orig	2014-10-06 18:27:44.000000000 +0200
+++ libinstaller/syslinux.h	2014-10-21 23:58:17.000000000 +0200
@@ -13,6 +13,7 @@
 #ifndef SYSLINUX_H
 #define SYSLINUX_H
 
+#include <unistd.h>
 #include <inttypes.h>
 #include "advconst.h"
 #include "setadv.h"
@@ -26,15 +27,15 @@
 #endif
 
 /* The standard boot sector and ldlinux image */
-extern unsigned char syslinux_bootsect[];
+extern unsigned char* syslinux_bootsect;
 extern const unsigned int syslinux_bootsect_len;
 extern const int syslinux_bootsect_mtime;
 
-extern unsigned char _slimg syslinux_ldlinux[];
-extern const unsigned int syslinux_ldlinux_len;
+extern unsigned char* _slimg syslinux_ldlinux;
+extern unsigned int syslinux_ldlinux_len;
 extern const int syslinux_ldlinux_mtime;
 
-extern unsigned char _slimg syslinux_ldlinuxc32[];
+extern unsigned char* _slimg syslinux_ldlinuxc32;
 extern const unsigned int syslinux_ldlinuxc32_len;
 
 #define boot_sector	syslinux_bootsect
@@ -42,7 +43,7 @@
 #define boot_image	syslinux_ldlinux
 #define boot_image_len	syslinux_ldlinux_len
 
-extern unsigned char syslinux_mbr[];
+extern unsigned char* syslinux_mbr;
 extern const unsigned int syslinux_mbr_len;
 extern const int syslinux_mbr_mtime;
 
