--- libclamav/zziplib/zzip-file.c.orig	Wed Feb  5 04:32:11 2003
+++ libclamav/zziplib/zzip-file.c	Wed Feb  5 04:35:05 2003
@@ -11,6 +11,7 @@
  *          that can be found in COPYING.ZZIP
  */
 
+#include <strings.h>
 #include <string.h>
 #include <sys/stat.h>
 #include <errno.h>
@@ -94,7 +95,6 @@
     return 0;
 }
 
-
 static int zzip_inflate_init(ZZIP_FILE *, struct zzip_dir_hdr *);
 
 /**
@@ -113,6 +113,7 @@
     struct zzip_dir_hdr * hdr = dir->hdr0;
     int (*cmp)(zzip_char_t*, zzip_char_t*);
  
+    (void)strcasecmp("","");
     cmp = (o_mode & ZZIP_CASEINSENSITIVE)? strcasecmp: strcmp;
 
     if (o_mode & ZZIP_IGNOREPATH)
