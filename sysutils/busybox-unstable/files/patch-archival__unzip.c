--- ./archival/unzip.c.orig	2014-01-01 00:45:23.000000000 +0100
+++ ./archival/unzip.c	2014-01-08 00:00:07.000000000 +0100
@@ -45,6 +45,8 @@
 #include "libbb.h"
 #include "bb_archive.h"
 
+#include <libgen.h>
+
 enum {
 #if BB_BIG_ENDIAN
 	ZIP_FILEHEADER_MAGIC = 0x504b0304,
