--- ./lib/ext2fs/ext2_fs.h.orig	2011-09-25 07:55:10.000000000 +0200
+++ ./lib/ext2fs/ext2_fs.h	2012-02-16 00:35:12.000000000 +0100
@@ -454,7 +454,7 @@
 
 #define i_dir_acl	i_size_high
 
-#if defined(__KERNEL__) || defined(__linux__)
+#if defined(__KERNEL__) || defined(__linux__) || defined(__FreeBSD__)
 #define i_reserved1	osd1.linux1.l_i_reserved1
 #define i_frag		osd2.linux2.l_i_frag
 #define i_fsize		osd2.linux2.l_i_fsize
