--- fax/filters/cdmfax/jetlib.cpp.orig	2023-06-02 08:02:35 UTC
+++ fax/filters/cdmfax/jetlib.cpp
@@ -49,8 +49,8 @@ Copyright (c) 1995 Hewlett-Packard Company.  All right
 */
 
 
-static char *LibRev = "PCL XL Stream Creator Library.  Revision p$Revision: 4.0 $";
-static char *LibCopyright = "(c) Copyright Hewlett-Packard Company, 1995, 1996, 1997.  All rights are reserved.";
+static const char *LibRev = "PCL XL Stream Creator Library.  Revision p$Revision: 4.0 $";
+static const char *LibCopyright = "(c) Copyright Hewlett-Packard Company, 1995, 1996, 1997.  All rights are reserved.";
 
 /*
  *  file: jetlib.c
@@ -7568,8 +7568,8 @@ HP_StdFuncPrefix HP_M2TIFF_CalcCompression(
     HP_pCharHuge lpfirst;
     HP_pCharHuge lpchar;
     HP_BOOL in_run, FourByteWordPad;
-    register HP_UByte count;
-    register HP_SInt16 state;
+    HP_UByte count;
+    HP_SInt16 state;
     HP_UByte padCount;
     HP_pUByte  lpEnd;
 
@@ -7704,8 +7704,8 @@ HP_StdFuncPrefix HP_M2TIFF_Compress(
     HP_pCharHuge lpfirst;
     HP_pCharHuge lpchar;
     HP_BOOL in_run,FourByteWordPad;
-    register HP_UByte count;
-    register HP_SInt16 state;
+    HP_UByte count;
+    HP_SInt16 state;
     HP_pCharHuge   lpEnd;
     HP_UByte padCount;
     
