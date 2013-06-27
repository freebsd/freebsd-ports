--- ./lib/ext2fs/ext2_fs.h.orig	2013-06-21 04:43:42.000000000 +0200
+++ ./lib/ext2fs/ext2_fs.h	2013-06-27 00:38:52.000000000 +0200
@@ -456,7 +456,7 @@
 
 #define i_dir_acl	i_size_high
 
-#if defined(__KERNEL__) || defined(__linux__)
+#if defined(__KERNEL__) || defined(__linux__) || defined(__FreeBSD__)
 #define i_reserved1	osd1.linux1.l_i_reserved1
 #define i_frag		osd2.linux2.l_i_frag
 #define i_fsize		osd2.linux2.l_i_fsize
