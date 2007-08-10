--- ./src/triSurface/triSurface/interfaces/NAS/readNAS.C.orig	Fri Jul  6 16:44:48 2007
+++ ./src/triSurface/triSurface/interfaces/NAS/readNAS.C	Sun Aug  5 00:21:48 2007
@@ -56,7 +56,7 @@
         {
             exp = -exp;
         }
-        return mantissa*pow10(exp);
+        return mantissa*pow(10.0, exp);
     }
     else
     {
