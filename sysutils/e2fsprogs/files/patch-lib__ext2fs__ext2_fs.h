--- ./lib/ext2fs/ext2_fs.h.orig	2013-12-29 05:18:02.000000000 +0100
+++ ./lib/ext2fs/ext2_fs.h	2014-01-06 23:26:48.000000000 +0100
@@ -456,7 +456,7 @@
 
 #define i_dir_acl	i_size_high
 
-#if defined(__KERNEL__) || defined(__linux__)
+#if defined(__KERNEL__) || defined(__linux__) || defined(__FreeBSD__)
 #define i_reserved1	osd1.linux1.l_i_reserved1
 #define i_frag		osd2.linux2.l_i_frag
 #define i_fsize		osd2.linux2.l_i_fsize
