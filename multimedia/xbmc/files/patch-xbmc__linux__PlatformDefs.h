--- ./xbmc/linux/PlatformDefs.h.orig	2010-06-09 07:05:59.000000000 +0200
+++ ./xbmc/linux/PlatformDefs.h	2010-12-01 12:17:34.264972083 +0100
@@ -37,11 +37,15 @@
 #include <unistd.h>
 #include <pthread.h>
 #include <string.h>
-#ifdef __APPLE__
+#if defined(__APPLE__)
 #include <stdio.h>
 #include <sys/sysctl.h>
 #include <mach/mach.h>
-#else
+#elif defined(__FreeBSD__)
+#include <stdio.h>
+#include <sys/sysctl.h>
+#include <sys/types.h>
+#else /* !__APPLE__ && !__FreeBSD__ */
 #include <sys/sysinfo.h>
 #endif
 #include <sys/time.h>
@@ -166,7 +170,7 @@
 #define CALLBACK    __stdcall
 #define WINAPI      __stdcall
 #define WINAPIV     __cdecl
-#ifndef __APPLE__
+#if !defined(__APPLE__) && !defined(__FreeBSD__)
 #define APIENTRY    WINAPI
 #else
 #define APIENTRY
@@ -190,16 +194,24 @@
 typedef void* HINSTANCE;
 typedef void* HMODULE;
 
+#if defined(__APPLE__) || defined(__FreeBSD__)
 #ifdef __APPLE__
 #include <AvailabilityMacros.h>
+#endif
 typedef int64_t   off64_t;
 typedef off_t     __off_t;
 typedef off64_t   __off64_t;
 typedef fpos_t fpos64_t;
+#ifdef __APPLE__
 #include <sched.h>
 #endif
+#endif
 
+#if defined(__FreeBSD__)
+typedef unsigned long  DWORD;
+#else
 typedef unsigned int  DWORD;
+#endif
 typedef unsigned short  WORD;
 typedef unsigned char   BYTE;
 typedef char        CHAR;
@@ -248,7 +260,11 @@
 typedef intptr_t (*FARPROC)(void);
 
 #define MAXWORD   0xffff
+#if defined(__FreeBSD__) && defined(__amd64__)
+#define MAXDWORD  0xffffffffffffffff
+#else
 #define MAXDWORD  0xffffffff
+#endif
 
 typedef DWORD LCID;
 typedef WORD* LPWORD;
@@ -303,7 +319,11 @@
   LONG DaylightBias;
 } TIME_ZONE_INFORMATION, *PTIME_ZONE_INFORMATION, *LPTIME_ZONE_INFORMATION;
 
+#if defined(__FreeBSD__) && defined(__amd64__)
+#define TIME_ZONE_ID_INVALID    ((DWORD)0xFFFFFFFFFFFFFFFF)
+#else
 #define TIME_ZONE_ID_INVALID    ((DWORD)0xFFFFFFFF)
+#endif
 #define TIME_ZONE_ID_UNKNOWN    0
 #define TIME_ZONE_ID_STANDARD   1
 #define TIME_ZONE_ID_DAYLIGHT   2
@@ -357,7 +377,7 @@
 #define _O_WRONLY O_WRONLY
 #define _off_t off_t
 
-#if defined(__APPLE__) && (MAC_OS_X_VERSION_MAX_ALLOWED < 1050)
+#if defined(__FreeBSD__) || (defined(__APPLE__) && (MAC_OS_X_VERSION_MAX_ALLOWED < 1050))
 #define __stat64 stat
 #define stat64 stat
 #define statfs64 statfs
