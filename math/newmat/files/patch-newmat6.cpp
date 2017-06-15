--- newmat6.cpp.orig	2006-09-09 12:51:25 UTC
+++ newmat6.cpp
@@ -428,7 +428,7 @@ void CroutMatrix::operator=(const CroutM
 {
    if (&gm == this) { REPORT tag_val = -1; return; }
    REPORT
-   if (indx > 0) { delete [] indx; indx = 0; }
+   if (indx) { delete [] indx; indx = 0; }
    ((CroutMatrix&)gm).get_aux(*this);
    Eq(gm);
 }
