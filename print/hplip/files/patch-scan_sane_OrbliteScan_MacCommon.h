--- scan/sane/OrbliteScan/MacCommon.h.orig	2022-02-23 07:41:05 UTC
+++ scan/sane/OrbliteScan/MacCommon.h
@@ -1,12 +1,12 @@
 #ifndef H_MacCommon
 #define H_MacCommon
 
-#ifndef __linux__
+#ifdef __APPLE__
 #include <CoreFoundation/CFPlugInCOM.h>
 #define __CFPlugInCOM_Included__
 #endif
 
-#ifdef __linux__
+#if defined(__linux__) || defined(__FreeBSD__)
 #    include "LinuxCommon.h"
 #endif
 
@@ -257,7 +257,7 @@ typedef struct _GUID {
 
 typedef GUID	CLSID;
 
-#ifndef __linux__
+#if !defined(__linux__) && !defined(__FreeBSD__)
 const extern CLSID CLSID_NULL;
 const extern GUID GUID_NULL;
 #else
