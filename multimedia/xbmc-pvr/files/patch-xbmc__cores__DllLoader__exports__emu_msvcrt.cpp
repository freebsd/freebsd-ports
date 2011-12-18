--- xbmc/cores/DllLoader/exports/emu_msvcrt.cpp.orig
+++ xbmc/cores/DllLoader/exports/emu_msvcrt.cpp
@@ -27,7 +27,7 @@
 #include <direct.h>
 #include <process.h>
 #else
-#ifndef __APPLE__
+#if !defined(__APPLE__) && !defined(__FreeBSD__)
 #include <mntent.h>
 #endif
 #endif
@@ -36,6 +36,7 @@
 #include <sys/timeb.h>
 #include "system.h" // for HAS_DVD_DRIVE
 #ifdef HAS_DVD_DRIVE
+#if !defined(__FreeBSD__)
   #ifdef _LINUX
     #include <sys/ioctl.h>
     #ifndef __APPLE__
@@ -45,6 +46,7 @@
     #endif
   #endif
 #endif
+#endif
 #include <fcntl.h>
 #include <time.h>
 #include <signal.h>
@@ -139,6 +141,8 @@ extern "C" void __stdcall init_emu_envir
   dll_putenv("OS=darwin");
 #elif defined(_LINUX)
   dll_putenv("OS=linux");
+#elif defined(__FreeBSD__)
+  dll_putenv("OS=freebsd");
 #else
   dll_putenv("OS=unknown");
 #endif
@@ -159,11 +163,11 @@ extern "C" void __stdcall init_emu_envir
     dll_putenv(string("PATH=.;" + _P("special://xbmc") + ";" + _P("special://xbmc/system/python")).c_str());
   }
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
@@ -1159,7 +1163,7 @@ extern "C"
   FILE* dll_fopen(const char* filename, const char* mode)
   {
     FILE* file = NULL;
-#if defined(_LINUX) && !defined(__APPLE__)
+#if defined(_LINUX) && !defined(__APPLE__) && !defined(__FreeBSD__)
     if (strcmp(filename, MOUNTED) == 0
     ||  strcmp(filename, MNTTAB) == 0)
     {
@@ -1267,7 +1271,7 @@ extern "C"
     {
       // it might be something else than a file, or the file is not emulated
       // let the operating system handle it
-#if defined(__APPLE__)
+#if defined(__APPLE__) || defined(__FreeBSD__)
       return fseek(stream, offset, origin);
 #else
       return fseeko64(stream, offset, origin);
@@ -1332,7 +1336,7 @@ extern "C"
     {
       // it might be something else than a file, or the file is not emulated
       // let the operating system handle it
-#if defined(__APPLE__)
+#if defined(__APPLE__) || defined(__FreeBSD__)
       return ftello(stream);
 #else
       return ftello64(stream);
@@ -1378,7 +1382,7 @@ extern "C"
       CLog::Log(LOGWARNING, "msvcrt.dll: dll_telli64 called, TODO: add 'int64 -> long' type checking");      //warning
 #ifndef _LINUX
       return (__int64)tell(fd);
-#elif defined(__APPLE__)
+#elif defined(__APPLE__) || defined(__FreeBSD__)
       return lseek(fd, 0, SEEK_CUR);
 #else
       return lseek64(fd, 0, SEEK_CUR);
@@ -1555,7 +1559,7 @@ extern "C"
     int ret;
 
     ret = dll_fgetpos64(stream, &tmpPos);
-#if !defined(_LINUX) || defined(__APPLE__)
+#if !defined(_LINUX) || defined(__APPLE__) || defined(__FreeBSD__)
     *pos = (fpos_t)tmpPos;
 #else
     pos->__pos = (off_t)tmpPos.__pos;
@@ -1568,7 +1572,7 @@ extern "C"
     CFile* pFile = g_emuFileWrapper.GetFileXbmcByStream(stream);
     if (pFile != NULL)
     {
-#if !defined(_LINUX) || defined(__APPLE__)
+#if !defined(_LINUX) || defined(__APPLE__) || defined(__FreeBSD__)
       *pos = pFile->GetPosition();
 #else
       pos->__pos = pFile->GetPosition();
@@ -1590,7 +1594,7 @@ extern "C"
     int fd = g_emuFileWrapper.GetDescriptorByStream(stream);
     if (fd >= 0)
     {
-#if !defined(_LINUX) || defined(__APPLE__)
+#if !defined(_LINUX) || defined(__APPLE__) || defined(__FreeBSD__)
       if (dll_lseeki64(fd, *pos, SEEK_SET) >= 0)
 #else
       if (dll_lseeki64(fd, (__off64_t)pos->__pos, SEEK_SET) >= 0)
@@ -1607,7 +1611,7 @@ extern "C"
     {
       // it might be something else than a file, or the file is not emulated
       // let the operating system handle it
-#if !defined(_LINUX) || defined(__APPLE__)
+#if !defined(_LINUX) || defined(__APPLE__) || defined(__FreeBSD__)
       return fsetpos(stream, pos);
 #else
       return fsetpos64(stream, pos);
@@ -1623,7 +1627,7 @@ extern "C"
     if (fd >= 0)
     {
       fpos64_t tmpPos;
-#if !defined(_LINUX) || defined(__APPLE__)
+#if !defined(_LINUX) || defined(__APPLE__) || defined(__FreeBSD__)
       tmpPos= *pos;
 #else
       tmpPos.__pos = (off64_t)(pos->__pos);
@@ -2069,7 +2073,7 @@ extern "C"
     return (char***)&t;
   }
 
-#ifdef _LINUX
+#if defined(_LINUX)
   int * __cdecl dll_errno(void)
   {
     return &errno;
@@ -2083,7 +2087,9 @@ extern "C"
        return -1;
 
 #ifdef HAS_DVD_DRIVE
-#ifndef __APPLE__
+#if defined(__FreeBSD__)
+	if (0)
+#elif !defined(__APPLE__)
     if(request == DVD_READ_STRUCT || request == DVD_AUTH)
 #else
     if(request == DKIOCDVDSENDKEY || request == DKIOCDVDREPORTKEY || request == DKIOCDVDREADSTRUCTURE)
@@ -2125,7 +2131,7 @@ extern "C"
       CLog::Log(LOGERROR, "%s - getmntent is not implemented for our virtual filesystem", __FUNCTION__);
       return NULL;
     }
-#if defined(_LINUX) && !defined(__APPLE__)
+#if defined(_LINUX) && !defined(__APPLE__) && !defined(__FreeBSD__)
     return getmntent(fp);
 #else
     CLog::Log(LOGWARNING, "%s - unimplemented function called", __FUNCTION__);
@@ -2150,7 +2156,7 @@ extern "C"
       else
         return 0;
     }
-#ifdef _LINUX
+#if defined(_LINUX)
     return 0;
 #else
     return _filbuf(fp);
