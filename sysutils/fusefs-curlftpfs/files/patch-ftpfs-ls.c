--- ftpfs-ls.c.orig	Tue Dec 12 11:09:37 2006
+++ ftpfs-ls.c	Tue Dec 12 11:09:42 2006
@@ -6,7 +6,12 @@
     See the file COPYING.
 */
 
+#ifndef __FreeBSD__
 #define _XOPEN_SOURCE 600
+#else
+#define _XOPEN_SOURCE
+#endif
+
 #include <time.h>
 #include <string.h>
 #include <sys/types.h>
@@ -27,7 +32,7 @@
   long nlink = 1;
   char user[33];
   char group[33];
-  long size;
+  unsigned long long size;
   char month[4];
   char day[3];
   char year[6];
@@ -42,25 +47,25 @@
 
 #define SPACES "%*[ \t]"
   res = sscanf(line,
-               "%11s" SPACES
+               "%11s"
                "%lu"  SPACES
                "%32s" SPACES
                "%32s" SPACES
-               "%lu"  SPACES
+               "%llu" SPACES
                "%3s"  SPACES
                "%2s"  SPACES
-               "%5s"  SPACES
+               "%5s"  "%*c"
                "%1023c",
                mode, &nlink, user, group, &size, month, day, year, file);
   if (res < 9) {
     res = sscanf(line,
-                 "%11s" SPACES
+                 "%11s"
                  "%32s" SPACES
                  "%32s" SPACES
-                 "%lu"  SPACES
+                 "%llu" SPACES
                  "%3s"  SPACES
                  "%2s"  SPACES
-                 "%5s"  SPACES
+                 "%5s"  "%*c"
                  "%1023c",
                  mode, user, group, &size, month, day, year, file);
     if (res < 8) {
@@ -156,7 +161,7 @@
   if (!strcmp(size, "<DIR>")) {
     sbuf->st_mode |= S_IFDIR;
   } else {
-    int nsize = strtol(size, NULL, 0);
+    unsigned long long nsize = strtoull(size, NULL, 0);
     sbuf->st_mode |= S_IFREG;
     sbuf->st_size = nsize;
     if (ftpfs.blksize) {
