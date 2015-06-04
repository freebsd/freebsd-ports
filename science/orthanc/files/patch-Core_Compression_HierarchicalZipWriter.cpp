--- Core/Compression/HierarchicalZipWriter.cpp.orig	2015-02-12 13:47:38 UTC
+++ Core/Compression/HierarchicalZipWriter.cpp
@@ -53,7 +53,7 @@ namespace Orthanc
       if (c == '^')
         c = ' ';
 
-      if (c < 128 && 
+      if (c <= 127 &&
           c >= 0)
       {
         if (isspace(c)) 
