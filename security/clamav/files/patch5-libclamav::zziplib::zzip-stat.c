--- libclamav/zziplib/zzip-stat.c.orig	Wed Feb  5 04:36:09 2003
+++ libclamav/zziplib/zzip-stat.c	Wed Feb  5 04:36:32 2003
@@ -32,6 +32,7 @@
     struct zzip_dir_hdr * hdr = dir->hdr0;
     int (*cmp)(zzip_char_t*, zzip_char_t*);
 
+    (void)strcasecmp("","");
     cmp = (flags & ZZIP_CASEINSENSITIVE) ? strcasecmp : strcmp;
 
     if (flags & ZZIP_IGNOREPATH)
