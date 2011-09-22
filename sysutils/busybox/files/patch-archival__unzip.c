--- ./archival/unzip.c.orig	2011-08-22 04:57:49.000000000 +0200
+++ ./archival/unzip.c	2011-09-22 23:05:09.000000000 +0200
@@ -34,6 +34,8 @@
 #include "libbb.h"
 #include "archive.h"
 
+#include <libgen.h>
+
 enum {
 #if BB_BIG_ENDIAN
 	ZIP_FILEHEADER_MAGIC = 0x504b0304,
