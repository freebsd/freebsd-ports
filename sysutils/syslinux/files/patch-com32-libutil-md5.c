diff -ubwr ./com32/libutil/md5.c ../../work/syslinux-3.72/com32/libutil/md5.c
--- ./com32/libutil/md5.c	2008-09-26 01:46:02.000000000 +0200
+++ ../../work/syslinux-3.72/com32/libutil/md5.c	2008-11-25 11:32:22.000000000 +0100
@@ -27,7 +27,7 @@
  */
 
 #include <string.h>
-#include <endian.h>
+#include <machine/endian.h>
 #include <md5.h>
 
 static void MD5Transform(uint32_t [4], const unsigned char [64]);
