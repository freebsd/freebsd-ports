--- newmat9.cpp.orig	Fri Sep  6 23:36:13 2002
+++ newmat9.cpp	Fri Sep  6 23:53:30 2002
@@ -23,11 +23,6 @@
 #define REPORT {}
 #endif
 
-// for G++ 3.01
-#ifndef _Ios_Fmtflags
-#define _Ios_Fmtflags long
-#endif
-
 ostream& operator<<(ostream& s, const BaseMatrix& X)
 {
    GeneralMatrix* gm = ((BaseMatrix&)X).Evaluate(); operator<<(s, *gm);
@@ -38,7 +33,13 @@
 ostream& operator<<(ostream& s, const GeneralMatrix& X)
 {
    MatrixRow mr((GeneralMatrix*)&X, LoadOnEntry);
-   int w = s.width();  int nr = X.Nrows();  _Ios_Fmtflags f = s.flags();
+   int w = s.width();  int nr = X.Nrows(); 
+#if defined __GNUG__  && __GNUG__ < 3
+   _Ios_Fmtflags 
+#else
+   ios_base::fmtflags
+#endif
+                 f = s.flags();
    s.setf(ios::fixed, ios::floatfield);
    for (int i=1; i<=nr; i++)
    {
