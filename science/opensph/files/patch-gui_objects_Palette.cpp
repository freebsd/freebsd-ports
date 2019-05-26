--- gui/objects/Palette.cpp.orig	2019-05-26 03:22:37 UTC
+++ gui/objects/Palette.cpp
@@ -2,6 +2,7 @@
 #include "io/Path.h"
 #include "objects/utility/StringUtils.h"
 #include <fstream>
+#include <cmath>
 
 NAMESPACE_SPH_BEGIN
 
@@ -41,12 +42,12 @@ float Palette::paletteToLinear(const float value) cons
     case PaletteScale::LINEAR:
         return value;
     case PaletteScale::LOGARITHMIC:
-        return exp10(value);
+        return std::pow(10.,value);
     case PaletteScale::HYBRID:
         if (value > 1.f) {
-            return exp10(value - 1.f);
+            return std::pow(10.,value - 1.f);
         } else if (value < -1.f) {
-            return -exp10(-value - 1.f);
+            return -std::pow(10.,-value - 1.f);
         } else {
             return value;
         }
@@ -142,12 +143,12 @@ float Palette::relativeToPalette(const float value) co
     case PaletteScale::LINEAR:
         return interpol;
     case PaletteScale::LOGARITHMIC:
-        return exp10(interpol);
+        return std::pow(10.,interpol);
     case PaletteScale::HYBRID:
         if (interpol > 1.f) {
-            return exp10(interpol - 1.f);
+            return std::pow(10.,interpol - 1.f);
         } else if (interpol < -1.f) {
-            return -exp10(-interpol - 1.f);
+            return -std::pow(10.,-interpol - 1.f);
         } else {
             return interpol;
         }
