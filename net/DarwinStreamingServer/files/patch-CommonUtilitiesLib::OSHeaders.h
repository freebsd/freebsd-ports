--- CommonUtilitiesLib/OSHeaders.h.orig	Wed May 18 17:01:14 2005
+++ CommonUtilitiesLib/OSHeaders.h	Sun Aug 13 00:34:52 2006
@@ -27,11 +27,20 @@
 #define OSHeaders_H
 #include <limits.h>
 
+#ifdef __amd64__
+#define CPU_64BIT
+#endif
+
 #define kSInt16_Max USHRT_MAX
 #define kUInt16_Max USHRT_MAX
 
+#ifdef CPU_64BIT
+#define kSInt32_Max INT_MAX
+#define kUInt32_Max UINT_MAX
+#else
 #define kSInt32_Max LONG_MAX
 #define kUInt32_Max ULONG_MAX
+#endif
 
 #define kSInt64_Max LONG_LONG_MAX
 #define kUInt64_Max ULONG_LONG_MAX
@@ -72,8 +81,13 @@
     typedef signed char         SInt8;
     typedef unsigned short      UInt16;
     typedef signed short        SInt16;
+#ifdef CPU_64BIT
+    typedef unsigned int        UInt32;
+    typedef signed int          SInt32;
+#else
     typedef unsigned long       UInt32;
     typedef signed long         SInt32;
+#endif
     typedef signed long long    SInt64;
     typedef unsigned long long  UInt64;
     typedef float               Float32;
@@ -81,7 +95,11 @@
     typedef UInt16              Bool16;
     typedef UInt8               Bool8;
     
+#ifdef CPU_64BIT
+    typedef unsigned int        FourCharCode;
+#else
     typedef unsigned long       FourCharCode;
+#endif
     typedef FourCharCode        OSType;
 
     #ifdef  FOUR_CHARS_TO_INT
