--- ./xbmc/cores/DllLoader/exports/emu_msvcrt.cpp.orig	2010-10-04 01:33:13.000000000 +0200
+++ ./xbmc/cores/DllLoader/exports/emu_msvcrt.cpp	2010-12-01 12:17:34.209596576 +0100
@@ -30,6 +30,7 @@
 #include <sys/stat.h>
 #include <sys/types.h>
 #include <sys/timeb.h>
+#if !defined(__FreeBSD__)
 #ifdef _LINUX
 #include <sys/ioctl.h>
 #ifndef __APPLE__
@@ -39,6 +40,7 @@
 #include <IOKit/storage/IODVDMediaBSDClient.h>
 #endif
 #endif
+#endif
 #include <fcntl.h>
 #include <time.h>
 #include <signal.h>
@@ -134,6 +136,8 @@
   dll_putenv("OS=darwin");
 #elif defined(_LINUX)
   dll_putenv("OS=linux");
+#elif defined(__FreeBSD__)
+  dll_putenv("OS=freebsd");
 #else
   dll_putenv("OS=unknown");
 #endif
@@ -141,11 +145,11 @@
   dll_putenv("PYTHONHOME=special://xbmc/system/python");
   dll_putenv("PATH=.;special://xbmc;special://xbmc/system/python");
   //dll_putenv("PYTHONCASEOK=1");
-  //dll_putenv("PYTHONDEBUG=1");
+  dll_putenv("PYTHONDEBUG=1");
   //dll_putenv("PYTHONVERBOSE=2"); // "1" for normal verbose, "2" for more verbose ?
   dll_putenv("PYTHONOPTIMIZE=1");
   //dll_putenv("PYTHONDUMPREFS=1");
-  //dll_putenv("THREADDEBUG=1");
+  dll_putenv("THREADDEBUG=1");
   //dll_putenv("PYTHONMALLOCSTATS=1");
   //dll_putenv("PYTHONY2K=1");
   dll_putenv("TEMP=special://temp/temp"); // for python tempdir
@@ -1141,7 +1145,7 @@
   FILE* dll_fopen(const char* filename, const char* mode)
   {
     FILE* file = NULL;
-#if defined(_LINUX) && !defined(__APPLE__)
+#if defined(_LINUX) && !defined(__APPLE__) && !defined(__FreeBSD__)
     if (strcmp(filename, MOUNTED) == 0
     ||  strcmp(filename, MNTTAB) == 0)
     {
@@ -1249,7 +1253,7 @@
     {
       // it might be something else than a file, or the file is not emulated
       // let the operating system handle it
-#if defined(__APPLE__)
+#if defined(__APPLE__) || defined(__FreeBSD__)
       return fseek(stream, offset, origin);
 #else
       return fseeko64(stream, offset, origin);
@@ -1314,7 +1318,7 @@
     {
       // it might be something else than a file, or the file is not emulated
       // let the operating system handle it
-#if defined(__APPLE__)
+#if defined(__APPLE__) || defined(__FreeBSD__)
       return ftello(stream);
 #else
       return ftello64(stream);
@@ -1360,7 +1364,7 @@
       CLog::Log(LOGWARNING, "msvcrt.dll: dll_telli64 called, TODO: add 'int64 -> long' type checking");      //warning
 #ifndef _LINUX
       return (__int64)tell(fd);
-#elif defined(__APPLE__)
+#elif defined(__APPLE__) || defined(__FreeBSD__)
       return lseek(fd, 0, SEEK_CUR);
 #else
       return lseek64(fd, 0, SEEK_CUR);
@@ -1537,7 +1541,7 @@
     int ret;
 
     ret = dll_fgetpos64(stream, &tmpPos);
-#if !defined(_LINUX) || defined(__APPLE__)
+#if !defined(_LINUX) || defined(__APPLE__) || defined(__FreeBSD__)
     *pos = (fpos_t)tmpPos;
 #else
     pos->__pos = (off_t)tmpPos.__pos;
@@ -1550,7 +1554,7 @@
     CFile* pFile = g_emuFileWrapper.GetFileXbmcByStream(stream);
     if (pFile != NULL)
     {
-#if !defined(_LINUX) || defined(__APPLE__)
+#if !defined(_LINUX) || defined(__APPLE__) || defined(__FreeBSD__)
       *pos = pFile->GetPosition();
 #else
       pos->__pos = pFile->GetPosition();
@@ -1572,7 +1576,7 @@
     int fd = g_emuFileWrapper.GetDescriptorByStream(stream);
     if (fd >= 0)
     {
-#if !defined(_LINUX) || defined(__APPLE__)
+#if !defined(_LINUX) || defined(__APPLE__) || defined(__FreeBSD__)
       if (dll_lseeki64(fd, *pos, SEEK_SET) >= 0)
 #else
       if (dll_lseeki64(fd, (__off64_t)pos->__pos, SEEK_SET) >= 0)
@@ -1589,7 +1593,7 @@
     {
       // it might be something else than a file, or the file is not emulated
       // let the operating system handle it
-#if !defined(_LINUX) || defined(__APPLE__)
+#if !defined(_LINUX) || defined(__APPLE__) || defined(__FreeBSD__)
       return fsetpos(stream, pos);
 #else
       return fsetpos64(stream, pos);
@@ -1605,7 +1609,7 @@
     if (fd >= 0)
     {
       fpos64_t tmpPos;
-#if !defined(_LINUX) || defined(__APPLE__)
+#if !defined(_LINUX) || defined(__APPLE__) || defined(__FreeBSD__)
       tmpPos= *pos;
 #else
       tmpPos.__pos = (off64_t)(pos->__pos);
@@ -2079,7 +2083,7 @@
     return (char***)&t;
   }
 
-#ifdef _LINUX
+#if defined(_LINUX)
   int * __cdecl dll_errno(void)
   {
     return &errno;
@@ -2090,8 +2094,9 @@
      CFile* pFile = g_emuFileWrapper.GetFileXbmcByDescriptor(fd);
      if (!pFile)
        return -1;
-
-#ifndef __APPLE__
+#if defined(__FreeBSD__)
+	if (0)
+#elif !defined(__APPLE__)
     if(request == DVD_READ_STRUCT || request == DVD_AUTH)
 #else
     if(request == DKIOCDVDSENDKEY || request == DKIOCDVDREPORTKEY || request == DKIOCDVDREADSTRUCTURE)
@@ -2129,7 +2134,7 @@
       CLog::Log(LOGERROR, "%s - getmntent is not implemented for our virtual filesystem", __FUNCTION__);
       return NULL;
     }
-#if defined(_LINUX) && !defined(__APPLE__)
+#if defined(_LINUX) && !defined(__APPLE__) && !defined(__FreeBSD__)
     return getmntent(fp);
 #else
     CLog::Log(LOGWARNING, "%s - unimplemented function called", __FUNCTION__);
@@ -2154,7 +2159,7 @@
       else
         return 0;
     }
-#ifdef _LINUX
+#if defined(_LINUX)
     return 0;
 #else
     return _filbuf(fp);
