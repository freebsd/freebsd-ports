--- include/CoCoA/config.H.orig	2020-06-09 22:18:10 UTC
+++ include/CoCoA/config.H
@@ -25,7 +25,7 @@ namespace CoCoA
   // This is the type used internally for "small" exponents in some PPMonoids
   // (PPMonoidEv, PPMonoidEvOv).  Also implies the number of bits used for a
   // "compressed entry" in an order vector (see OrdvArith).
-  typedef unsigned int SmallExponent_t;
+  typedef unsigned short SmallExponent_t;
 
   // **ROUNDING**
   // The way CoCoALib rounds halves is determined by the fns RoundDiv in
