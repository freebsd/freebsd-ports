--- ./xbmc/cores/DllLoader/exports/emu_msvcrt.cpp.orig	2011-12-23 04:12:21.000000000 +0100
+++ ./xbmc/cores/DllLoader/exports/emu_msvcrt.cpp	2012-01-02 10:14:38.000000000 +0100
@@ -27,21 +27,23 @@
 #include <direct.h>
 #include <process.h>
 #else
-#ifndef __APPLE__
+#if !defined(__APPLE__) && !defined(__FreeBSD__)
 #include <mntent.h>
 #endif
 #endif
 #include <sys/stat.h>
 #include <sys/types.h>
+#if !defined(__FreeBSD__)
 #include <sys/timeb.h>
+#endif
 #include "system.h" // for HAS_DVD_DRIVE
 #ifdef HAS_DVD_DRIVE
   #ifdef _LINUX
     #include <sys/ioctl.h>
-    #ifndef __APPLE__
-      #include <linux/cdrom.h>
-    #else
+    #ifdef __APPLE__
       #include <IOKit/storage/IODVDMediaBSDClient.h>
+    #elif !defined(__FreeBSD__)
+      #include <linux/cdrom.h>
     #endif
   #endif
 #endif
@@ -1159,7 +1161,7 @@
   FILE* dll_fopen(const char* filename, const char* mode)
   {
     FILE* file = NULL;
-#if defined(_LINUX) && !defined(__APPLE__)
+#if defined(_LINUX) && !defined(__APPLE__) && !defined(__FreeBSD__)
     if (strcmp(filename, MOUNTED) == 0
     ||  strcmp(filename, MNTTAB) == 0)
     {
@@ -1267,7 +1269,7 @@
     {
       // it might be something else than a file, or the file is not emulated
       // let the operating system handle it
-#if defined(__APPLE__)
+#if defined(__APPLE__) || defined(__FreeBSD__)
       return fseek(stream, offset, origin);
 #else
       return fseeko64(stream, offset, origin);
@@ -1332,7 +1334,7 @@
     {
       // it might be something else than a file, or the file is not emulated
       // let the operating system handle it
-#if defined(__APPLE__)
+#if defined(__APPLE__) || defined(__FreeBSD__)
       return ftello(stream);
 #else
       return ftello64(stream);
@@ -1378,7 +1380,7 @@
       CLog::Log(LOGWARNING, "msvcrt.dll: dll_telli64 called, TODO: add 'int64 -> long' type checking");      //warning
 #ifndef _LINUX
       return (__int64)tell(fd);
-#elif defined(__APPLE__)
+#elif defined(__APPLE__) || defined(__FreeBSD__)
       return lseek(fd, 0, SEEK_CUR);
 #else
       return lseek64(fd, 0, SEEK_CUR);
@@ -1555,7 +1557,7 @@
     int ret;
 
     ret = dll_fgetpos64(stream, &tmpPos);
-#if !defined(_LINUX) || defined(__APPLE__)
+#if !defined(_LINUX) || defined(__APPLE__) || defined(__FreeBSD__)
     *pos = (fpos_t)tmpPos;
 #else
     pos->__pos = (off_t)tmpPos.__pos;
@@ -1568,7 +1570,7 @@
     CFile* pFile = g_emuFileWrapper.GetFileXbmcByStream(stream);
     if (pFile != NULL)
     {
-#if !defined(_LINUX) || defined(__APPLE__)
+#if !defined(_LINUX) || defined(__APPLE__) || defined(__FreeBSD__)
       *pos = pFile->GetPosition();
 #else
       pos->__pos = pFile->GetPosition();
@@ -1590,7 +1592,7 @@
     int fd = g_emuFileWrapper.GetDescriptorByStream(stream);
     if (fd >= 0)
     {
-#if !defined(_LINUX) || defined(__APPLE__)
+#if !defined(_LINUX) || defined(__APPLE__) || defined(__FreeBSD__)
       if (dll_lseeki64(fd, *pos, SEEK_SET) >= 0)
 #else
       if (dll_lseeki64(fd, (__off64_t)pos->__pos, SEEK_SET) >= 0)
@@ -1607,7 +1609,7 @@
     {
       // it might be something else than a file, or the file is not emulated
       // let the operating system handle it
-#if !defined(_LINUX) || defined(__APPLE__)
+#if !defined(_LINUX) || defined(__APPLE__) || defined(__FreeBSD__)
       return fsetpos(stream, pos);
 #else
       return fsetpos64(stream, pos);
@@ -1623,7 +1625,7 @@
     if (fd >= 0)
     {
       fpos64_t tmpPos;
-#if !defined(_LINUX) || defined(__APPLE__)
+#if !defined(_LINUX) || defined(__APPLE__) || defined(__FreeBSD__)
       tmpPos= *pos;
 #else
       tmpPos.__pos = (off64_t)(pos->__pos);
@@ -2082,7 +2084,7 @@
      if (!pFile)
        return -1;
 
-#ifdef HAS_DVD_DRIVE
+#if defined(HAS_DVD_DRIVE) && !defined(__FreeBSD__)
 #ifndef __APPLE__
     if(request == DVD_READ_STRUCT || request == DVD_AUTH)
 #else
@@ -2125,7 +2127,7 @@
       CLog::Log(LOGERROR, "%s - getmntent is not implemented for our virtual filesystem", __FUNCTION__);
       return NULL;
     }
-#if defined(_LINUX) && !defined(__APPLE__)
+#if defined(_LINUX) && !defined(__APPLE__) && !defined(__FreeBSD__)
     return getmntent(fp);
 #else
     CLog::Log(LOGWARNING, "%s - unimplemented function called", __FUNCTION__);
