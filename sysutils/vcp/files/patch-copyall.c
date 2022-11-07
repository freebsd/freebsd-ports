--- copyall.c.orig	2022-11-06 12:59:04 UTC
+++ copyall.c
@@ -16,10 +16,6 @@
 #include "copy.h"
 #include "screen.h"
 
-#ifndef _POSIX_SOURCE
-#define st_mtime st_mtimespec.tv_sec
-#endif
-
 int copyall(char *args[],int fts_opt,int type) {
 	FTS *ftsarg;
 	FTSENT *ftsf;
