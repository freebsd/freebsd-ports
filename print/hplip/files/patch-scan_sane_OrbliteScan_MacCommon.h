--- scan/sane/OrbliteScan/MacCommon.h.orig	2019-10-22 06:21:36 UTC
+++ scan/sane/OrbliteScan/MacCommon.h
@@ -1,7 +1,7 @@
 #ifndef H_MacCommon
 #define H_MacCommon
 
-#ifndef __linux__
+#if !defined(__linux__) && !defined(__FreeBSD__)
 #include <CoreFoundation/CFPlugInCOM.h>
 #define __CFPlugInCOM_Included__
 #endif
@@ -10,6 +10,10 @@
 #    include "LinuxCommon.h"
 #endif
 
+#if defined(__FreeBSD__)
+#    include "BSDCommon.h"
+#endif
+
 #include <stdio.h>
 #include <string.h>
 #include <stdlib.h>
@@ -257,7 +261,7 @@ typedef struct _GUID {
 
 typedef GUID	CLSID;
 
-#ifndef __linux__
+#if !defined(__linux__) && !defined(__FreeBSD__)
 const extern CLSID CLSID_NULL;
 const extern GUID GUID_NULL;
 #else
