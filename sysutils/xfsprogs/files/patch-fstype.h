--- libdisk/fstype.h.orig	Tue Aug 19 15:30:08 2003
+++ libdisk/fstype.h	Tue Aug 19 15:31:13 2003
@@ -135,6 +135,8 @@
 /* From jj@sunsite.ms.mff.cuni.cz Mon Mar 23 15:19:05 1998 */
 #define UFS_SUPER_MAGIC_LE 0x00011954
 #define UFS_SUPER_MAGIC_BE 0x54190100
+#define UFS2_SUPER_MAGIC_LE   0x19540119 
+#define UFS2_SUPER_MAGIC_BE   0x19015419
 struct ufs_super_block {
     u_char     s_dummy[0x55c];
     u_char     s_magic[4];
