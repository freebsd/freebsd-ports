--- ./archival/unzip.c.orig	2012-07-02 14:08:25.000000000 +0000
+++ ./archival/unzip.c	2012-07-17 02:08:37.000000000 +0000
@@ -34,6 +34,8 @@
 #include "libbb.h"
 #include "bb_archive.h"
 
+#include <libgen.h>
+
 enum {
 #if BB_BIG_ENDIAN
 	ZIP_FILEHEADER_MAGIC = 0x504b0304,
