--- src/libLfunction/Lglobals.h.orig	2021-12-19 17:09:15 UTC
+++ src/libLfunction/Lglobals.h
@@ -52,8 +52,20 @@ using namespace std;
 //---------------------------------------------------------------------------
 
 
-#include "Lcomplex.h"     //for complex numbers
+#include <complex>
 typedef complex<Double> Complex;
+inline Complex operator* (const Complex &l, int r) { return l *  Double(r); }
+inline Complex operator/ (const Complex &l, int r) { return l /  Double(r); }
+inline Complex operator+ (const Complex &l, int r) { return l +  Double(r); }
+inline Complex operator- (const Complex &l, int r) { return l -  Double(r); }
+inline bool    operator==(const Complex &l, int r) { return l == Double(r); }
+inline bool    operator!=(const Complex &l, int r) { return l != Double(r); }
+
+inline Complex operator*(int l, const Complex &r) { return r * l; }
+inline Complex operator+(int l, const Complex &r) { return r + l; }
+
+inline Complex operator/(int l, const Complex &r) { return Double(l) / r; }
+inline Complex operator-(int l, const Complex &r) { return Double(l) - r; }
 
 #include "Lcommon.h"
 
