--- newmat9.cpp.orig	Wed Oct 17 14:46:04 2001
+++ newmat9.cpp	Tue Oct  1 11:00:36 2002
@@ -24,8 +24,10 @@
 #endif
 
 // for G++ 3.01
-#ifndef _Ios_Fmtflags
+#if __GNUC__ < 3
 #define _Ios_Fmtflags long
+#else
+#define _Ios_Fmtflags ios_base::fmtflags
 #endif
 
 ostream& operator<<(ostream& s, const BaseMatrix& X)
