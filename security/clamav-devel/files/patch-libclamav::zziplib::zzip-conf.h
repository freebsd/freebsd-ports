--- libclamav/zziplib/zzip-conf.h.orig	Mon Aug  4 06:25:30 2003
+++ libclamav/zziplib/zzip-conf.h	Thu Aug  7 03:48:35 2003
@@ -29,6 +29,10 @@
 # endif
 #endif
 
+# ifdef ZZIP_HAVE_SYS_TYPES_H
+# include <sys/types.h>
+# endif
+
 /* especially win32 platforms do not declare off_t so far - see zzip-msvc.h */
 #ifndef _zzip_off_t
 #ifdef   ZZIP_off_t
