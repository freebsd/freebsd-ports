--- ./binwalk.c.orig	2012-10-07 07:44:55.000000000 -0400
+++ ./binwalk.c	2012-10-07 07:57:58.000000000 -0400
@@ -78,7 +78,12 @@
 	
 	/* Initialize default configuration settings */
 	/* Thanks to dannyb for these flags - much improved scan times! */
+#include <sys/param.h>
+#if __FreeBSD_version >= 800086
 	config.flags = MAGIC_NO_CHECK_TEXT | MAGIC_NO_CHECK_ENCODING;
+#else
+	config.flags = MAGIC_NO_CHECK_ASCII;
+#endif
 	config.align = DEFAULT_BYTE_ALIGN;
 	config.smart = 1;
 
