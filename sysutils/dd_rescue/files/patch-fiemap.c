--- fiemap.c.orig	2024-08-22 17:41:01 UTC
+++ fiemap.c
@@ -288,7 +288,6 @@ char* strippart(const char* partname)
 	return _fulldevnm;
 }
 
-#include <linux/hdreg.h>
 /* Get partition offset in sectors for block device devnm */
 int64_t partoffset(const char* devnm)
 {
