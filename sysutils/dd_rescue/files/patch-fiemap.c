--- fiemap.c.orig	2015-04-15 08:56:38 UTC
+++ fiemap.c
@@ -286,7 +286,6 @@ char* strippart(const char* partname)
 	return _fulldevnm;
 }
 
-#include <linux/hdreg.h>
 /* Get partition offset in sectors for block device devnm */
 int64_t partoffset(const char* devnm)
 {
