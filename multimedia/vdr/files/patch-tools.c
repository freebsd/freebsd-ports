--- tools.c.orig	2026-09-26 17:58:30 UTC
+++ tools.c
@@ -20,8 +20,8 @@ extern "C" {
 }
 #include <locale.h>
 #include <stdlib.h>
+#include <sys/statvfs.h>
 #include <sys/time.h>
-#include <sys/vfs.h>
 #include <time.h>
 #include <unistd.h>
 #include <utime.h>
@@ -509,9 +509,9 @@ int FreeDiskSpaceMB(const char *Director
   if (UsedMB)
      *UsedMB = 0;
   int Free = 0;
-  struct statfs statFs;
-  if (statfs(Directory, &statFs) == 0) {
-     double blocksPerMeg = 1024.0 * 1024.0 / statFs.f_bsize;
+  struct statvfs statFs;
+  if (statvfs(Directory, &statFs) == 0) {
+     double blocksPerMeg = 1024.0 * 1024.0 / statFs.f_frsize;
      if (UsedMB)
         *UsedMB = int((statFs.f_blocks - statFs.f_bfree) / blocksPerMeg);
      Free = int(statFs.f_bavail / blocksPerMeg);
@@ -715,7 +715,7 @@ char *ReadLink(const char *FileName)
 {
   if (!FileName)
      return NULL;
-  char *TargetName = canonicalize_file_name(FileName);
+  char *TargetName = realpath(FileName, NULL);
   if (!TargetName) {
      if (errno == ENOENT) // file doesn't exist
         TargetName = strdup(FileName);
@@ -1657,7 +1657,7 @@ cReadDir::~cReadDir()
 struct dirent *cReadDir::Next(void)
 {
   if (directory) {
-#if !__GLIBC_PREREQ(2, 24) // readdir_r() is deprecated as of GLIBC 2.24
+#ifdef VDR_USE_READDIR_R
      while (readdir_r(directory, &u.d, &result) == 0 && result) {
 #else
      while ((result = readdir(directory)) != NULL) {
