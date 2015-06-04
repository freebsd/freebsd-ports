--- Core/ImageFormats/ImageProcessing.cpp.orig	2015-02-12 13:47:38 UTC
+++ Core/ImageFormats/ImageProcessing.cpp
@@ -209,7 +209,7 @@ namespace Orthanc
   void MultiplyConstantInternal(ImageAccessor& image,
                                 float factor)
   {
-    if (abs(factor - 1.0f) <= std::numeric_limits<float>::epsilon())
+    if (std::abs(factor - 1.0f) <= std::numeric_limits<float>::epsilon())
     {
       return;
     }
