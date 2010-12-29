--- ./xbmc/linux/XFileUtils.cpp.orig	2010-08-21 12:04:13.000000000 +0200
+++ ./xbmc/linux/XFileUtils.cpp	2010-12-01 12:17:34.259935534 +0100
@@ -29,7 +29,7 @@
 #include "XHandle.h"
 #include <sys/types.h>
 #include <sys/stat.h>
-#ifndef __APPLE__
+#if !defined(__APPLE__) && !defined(__FreeBSD__)
 #include <sys/vfs.h>
 #else
 #include <sys/param.h>
@@ -60,7 +60,7 @@
   strPath.Replace("\\","/");
 
   // if the file name is a directory then we add a * to look for all files in this directory
-#ifdef __APPLE__
+#if defined(__APPLE__) || defined(__FreeBSD__)
   DIR *testDir = opendir(strPath.c_str());
 #else
   DIR *testDir = opendir(szPath);
@@ -552,7 +552,7 @@
     nMode = SEEK_END;
 
   off64_t currOff;
-#ifdef __APPLE__
+#if defined(__APPLE__) || defined(__FreeBSD__)
   currOff = lseek(hFile->fd, offset, nMode);
 #else
   currOff = lseek64(hFile->fd, offset, nMode);
@@ -598,7 +598,7 @@
 
   memset(lpTimeZoneInformation, 0, sizeof(TIME_ZONE_INFORMATION));
 
-#ifdef __APPLE__
+#if defined(__APPLE__)
   struct timezone tz;
   gettimeofday(NULL, &tz);
   lpTimeZoneInformation->Bias = tz.tz_minuteswest;
@@ -621,7 +621,7 @@
     return false;
 
   // get the current offset
-#ifdef __APPLE__
+#if defined(__APPLE__) || defined(__FreeBSD__)
   off64_t currOff = lseek(hFile->fd, 0, SEEK_CUR);
 #else
   off64_t currOff = lseek64(hFile->fd, 0, SEEK_CUR);
@@ -649,7 +649,7 @@
 
   off64_t toMove = liDistanceToMove.QuadPart;
 
-#ifdef __APPLE__
+#if defined(__APPLE__) || defined(__FreeBSD__)
   off64_t currOff = lseek(hFile->fd, toMove, nMode);
 #else
   off64_t currOff = lseek64(hFile->fd, toMove, nMode);
