--- lib/ext2fs/ext2_fs.h.orig	2014-08-02 20:26:22 UTC
+++ lib/ext2fs/ext2_fs.h
@@ -461,7 +461,7 @@
 
 #define i_dir_acl	i_size_high
 
-#if defined(__KERNEL__) || defined(__linux__)
+#if defined(__KERNEL__) || defined(__linux__) || defined(__FreeBSD__)
 #define i_reserved1	osd1.linux1.l_i_reserved1
 #define i_frag		osd2.linux2.l_i_frag
 #define i_fsize		osd2.linux2.l_i_fsize
