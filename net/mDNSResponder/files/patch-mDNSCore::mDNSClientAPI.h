--- mDNSCore/mDNSClientAPI.h.old	Tue Mar  2 15:01:04 2004
+++ mDNSCore/mDNSClientAPI.h	Fri Mar 19 15:26:43 2004
@@ -618,9 +618,12 @@
 typedef unsigned char  mDNSu8;
 typedef   signed short mDNSs16;
 typedef unsigned short mDNSu16;
-#if _LP64
+#if defined(_LP64) || defined(__LP64__)
 typedef   signed int   mDNSs32;
 typedef unsigned int   mDNSu32;
+#elif defined(_ILP64) || defined(__ILP64__)
+typedef   signed int32 mDNSs32;
+typedef unsigned int32 mDNSu32;
 #else
 typedef   signed long  mDNSs32;
 typedef unsigned long  mDNSu32;
