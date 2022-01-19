--- core/Common/DocxFormat/Source/Base/Types_32.h.orig	2021-09-30 12:13:32 UTC
+++ core/Common/DocxFormat/Source/Base/Types_32.h
@@ -38,7 +38,7 @@
 	typedef unsigned __int16	_UINT16;
 	typedef unsigned __int32	_UINT32;
 	typedef unsigned __int64	_UINT64;
-#elif __linux__
+#elif defined(__linux__) || defined(__FreeBSD__)
         typedef int16_t             _INT16;
         typedef int32_t             _INT32;
         typedef int64_t             _INT64;
