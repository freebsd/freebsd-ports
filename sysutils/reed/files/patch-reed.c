$FreeBSD$

--- reed.c.orig	2002-11-09 00:59:08 UTC
+++ reed.c
@@ -24,13 +24,12 @@
 
 #include <sys/types.h>
 #include <sys/stat.h>
-#include <sys/dir.h>
+#include <dirent.h>
 
 #include <ctype.h>
 #include <curses.h>
 #include <dirent.h>
 #include <errno.h>
-#include <getopt.h>
 #include <grp.h>
 #include <limits.h>
 #include <pwd.h>
