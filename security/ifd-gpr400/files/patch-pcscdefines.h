--- pcscdefines.h.orig	Thu Aug  9 03:14:27 2001
+++ pcscdefines.h	Sun Sep  8 18:10:47 2002
@@ -18,6 +18,7 @@
 
 /* Defines a list of pseudo types. */
 
+#if !defined(__FreeBSD__)
   typedef unsigned long      DWORD;
   typedef unsigned long*     PDWORD;
   typedef unsigned char      UCHAR;
@@ -25,6 +26,7 @@
   typedef char*              LPSTR;
   typedef long               RESPONSECODE;
   typedef void               VOID;
+#endif
 
   #define MAX_RESPONSE_SIZE  264
   #define MAX_ATR_SIZE       33
