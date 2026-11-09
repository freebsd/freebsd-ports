--- src/INTERP_KERNEL/ExprEval/InterpKernelUnit.cxx.orig	2025-10-15 11:21:58 UTC
+++ src/INTERP_KERNEL/ExprEval/InterpKernelUnit.cxx
@@ -36,9 +36,9 @@ UnitDataBase::GetUniqueMapForExpr()
     return db;
 }
 
-static const char InterpKernelMuAscii[2] = {-0x4B, 0x0};
+static const char InterpKernelMuAscii[2] = "\xB5";
 
-static const char InterpKernelMuUnicode[3] = {-0x3E, -0x4B, 0x0};
+static const char InterpKernelMuUnicode[3] = "\xC2\xB5";
 
 const char *UnitDataBase::PREF_POW10[NB_OF_PREF_POW10] = {
     "y", "z", "a", "f", "p", "n", InterpKernelMuAscii, InterpKernelMuUnicode, "u", "m", "c", "d", "da", "h", "k", "M",
@@ -49,11 +49,11 @@ const double UnitDataBase::POW10[NB_OF_PREF_POW10] = {
                                                       1e-6,  1e-3,  1e-2,  1e-1,  1e1,   1e2,  1e3,  1e6,
                                                       1e9,   1e12,  1e15,  1e18,  1e21,  1e24};
 
-static const char InterpKernelDegreeCAscii[3] = {-0x50, 0x43, 0x0};
+static const char InterpKernelDegreeCAscii[3] = "\xB0" "C";
 
-static const char InterpKernelDegreeCUnicode[4] = {-0x3E, -0x50, 0x43, 0x0};
+static const char InterpKernelDegreeCUnicode[4] = "\xC2\xB0" "C";
 
-static const char InterpKernelDegreeCUnicodeWin[3] = {-0x08, 0x43, 0x0};
+static const char InterpKernelDegreeCUnicodeWin[3] = "\xF8" "C";
 
 const char *UnitDataBase::UNITS_RECOGN[NB_OF_UNITS_RECOGN] = {
     "g",
