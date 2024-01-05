--- src/common/CupsFilter.h.orig	2012-02-07 13:22:37 UTC
+++ src/common/CupsFilter.h
@@ -22,6 +22,7 @@
 #define hfc4bbdea_8a1b_427c_9ab5_50b84576b19e
 
 #include <cups/cups.h>
+#include <cups/ppd.h>
 #include <cups/raster.h>
 #include <memory>
 #include <string>
@@ -132,7 +133,7 @@ CCupsFilter<D, DI, LM>::Run(int argc, char* argv[])
     bool UseCustomHalftoning    = PageHeader.cupsBitsPerPixel > 1;
     bool IsProcessLineSupported = true;
 
-    std::auto_ptr<CHalftoneFilter> H;
+    std::unique_ptr<CHalftoneFilter> H;
     if (UseCustomHalftoning)
     {
       if (HalftoningMethod_ == "NLL")
